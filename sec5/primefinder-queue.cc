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
#define N_INTERVALS 1000

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
            n_primes += 1;
        }
    }

    return n_primes;
}

void primefinder_helper(std::queue<range_t> *range_queue, std::mutex *ranges_mtx) {
    // for logging purposes
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



    // TODO: Implement the work loop! The thread will continually process ranges from the range
    // queue until all ranges have been processed.
    while (true) {
        // 1. Pop off the current range to process from the range queue. Make sure to synchronize
        // access!
        //
        // [Hint: if the range queue is empty, what should you do?]

        // 2. Pass the range into the count_primes_in_range function. Note that the function now
        // returns the number of primes in the given range!

        // 3. Increment the global num_primes counter. Make sure to synchronize access!
    }



    // for logging purposes
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /
                     1000000.0
              << "[s] (thread " << std::this_thread::get_id() << ")" << std::endl;
}

int main() {
    // for logging purposes
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



    // break up into smaller ranges to process
    std::queue<range_t> range_queue;
    std::mutex ranges_mtx;

    int step = MAX_LIMIT / N_INTERVALS;
    for (int i = 0; i < N_INTERVALS; i++) {
        range_queue.push({i * step, (i + 1) * step});
    }

    // TODO: make N_THREADS threads that each run the primefinder_helper function. Pass in the
    // appropriate arguments!
    std::vector<std::thread> threads(N_THREADS);

    // TODO: make sure to join the threads once done!

    std::cout << "num_primes: " << num_primes << std::endl;



    // for logging purposes
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /
                     1000000.0
              << "[s] (TOTAL)" << std::endl;
    return 0;
}
