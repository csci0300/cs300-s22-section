#include <atomic>
#include <chrono>
#include <cmath>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#define N_THREADS 4
#define MAX_LIMIT 20000000 // primes we are searching for

/**
 * Struct representing an int range.
 */
typedef struct {
    int min;
    int max;
} range_t;

// global counter for primes.
int num_primes = 0;
std::mutex num_primes_mtx;
// std::atomic<int> num_primes = 0;

/**
 * Counts the number of primes within a range.
 *
 * Inputs:
 * - range: the range of integers to search [min, max)
 */
void count_primes_in_range(range_t range) {
    // for logging purposes
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



    // to ignore 0 and 1
    int min = range.min > 1 ? range.min : 2;
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
            // synchronize access to the counter!
            std::unique_lock<std::mutex> lock(num_primes_mtx);
            // num_primes_mtx.lock();
            num_primes += 1;
            // num_primes_mtx.unlock();
        }
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



    // store threads for joining later
    std::vector<std::thread> threads(N_THREADS);

    int step = MAX_LIMIT / N_THREADS;
    for (int i = 0; i < N_THREADS; i++) {
        range_t curr_range = {i * step, (i + 1) * step};
        threads[i] = std::thread(count_primes_in_range, curr_range);
    }

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
