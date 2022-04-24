#include <atomic>
#include <cmath>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#define N_THREADS 4
#define MAX_LIMIT 20000000 // primes we are searching for
#define N_STEPS 1000

#define ENDS_IN 7

/**
 * Struct representing an int range.
 */
typedef struct {
    int min;
    int max;
} range_t;

// global counter for number of primes
int num_primes = 0;
std::mutex num_primes_mtx;
// std::atomic<int> num_primes = 0;

// queue for primes that ends in (ENDS_IN)!
std::queue<int> ends_queue;
std::mutex ends_mtx;
std::condition_variable ends_cv;
std::atomic<bool> done = false;



/**
 * Counts the number of primes within a range.
 *
 * Inputs:
 * - range: the range of integers to search [min, max)
 *
 * Returns:
 * - the number of primes within the range
 */
int count_primes_in_range(range_t range) {
    // to ignore 0 and 1
    int min = range.min > 1 ? range.min : 2;

    int n_primes = 0;
    for (int candidate = min; candidate < range.max; candidate++) {
        bool is_prime = true;

        int limit = ceil(sqrt(candidate));
        for (int factor = 2; factor <= limit; factor++) {
            if (candidate % factor == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            if (candidate % 10 == ENDS_IN) {
                ends_mtx.lock();
                if (ends_queue.empty()) {
                    ends_cv.notify_one();
                }
                ends_queue.push(candidate);
                ends_mtx.unlock();
            }

            n_primes += 1;
        }
    }

    return n_primes;
}

void primefinder_helper(std::queue<range_t> *ranges, std::mutex *ranges_mtx) {
    while (true) {
        ranges_mtx->lock();
        if (ranges->empty()) {
            ranges_mtx->unlock();
            break;
        }
        range_t curr_range = ranges->front();
        ranges->pop();
        ranges_mtx->unlock();

        int primes_in_range = count_primes_in_range(curr_range);

        num_primes_mtx.lock();
        num_primes += primes_in_range;
        num_primes_mtx.unlock();

        if (curr_range.max == MAX_LIMIT) {
            done.store(true);
            ends_cv.notify_one();
            break;
        }
    }
}

int main() {
    // for logging purposes
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



    // break up into smaller ranges to process
    std::queue<range_t> ranges;
    std::mutex ranges_mtx;
    int step = MAX_LIMIT / N_STEPS;
    for (int i = 0; i < N_STEPS; i++) {
        ranges.push({i * step, (i + 1) * step});
    }

    // store threads for joining later
    std::vector<std::thread> threads(N_THREADS);
    for (int i = 0; i < N_THREADS; i++) {
        threads[i] = std::thread(primefinder_helper, &ranges, &ranges_mtx);
    }

    std::unique_lock<std::mutex> lock(ends_mtx);
    while (!done.load()) {
        while (!done.load() && ends_queue.empty()) {
            ends_cv.wait(lock);
        }

        if (!done.load()) {
            std::cout << ends_queue.front() << std::endl;
            ends_queue.pop();
        }
    }
    lock.unlock();


    // wait for threads to finish
    for (std::thread &t : threads) {
        t.join();
    }

    std::cout << "num_primes: " << num_primes << std::endl;



    // for logging purposes
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /
                     1000000.0
              << "[s] (TOTAL)" << std::endl;
    return 0;
}
