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
// TODO: which synchronization primitives do we need?
//
// Think about what we need to protect access to:
// - you only want one thread to be able to access `ends_queue` at a time.
// - your main thread should be able to pop off the `ends_queue` and print the value whenever a
// worker thread finds a prime that ends in the specified digit. If none exists, the main thread
// should wait.
// - your main thread should stop waiting for new values once all threads are done.



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
            // TODO: if the prime ends in the specific value, append to ends_queue.
            if (candidate % 10 == ENDS_IN) {
                // 1. Check if ends_queue is empty. Make sure to synchronize access!
                //
                // [Hint: if the queue was previously empty, do you need to do anything else?]

                // 2. Push the prime to the end of the queue.
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

        // TODO: does anything need to be done here, with respect to ends_queue?
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

    // TODO: print out any prime that ends in the specified digit (defined in ENDS_IN), until all
    // primes are processed!
    //
    // Hints:
    // - You'll want to synchronize access to ends_queue.
    // - If the threads are done, you shouldn't wait on the queue anymore. Which synchronization
    // primitive can help you with this?
    // - Similarly, if there is currently nothing on the ends_queue, you'll want to wait until
    // another prime is added. Which synchronization primitive can help you with this?


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
