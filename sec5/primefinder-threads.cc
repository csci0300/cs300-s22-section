#include <atomic>
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
// TODO: synchronize access with a mutex!
int num_primes = 0;

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
    // TODO: is there anything within the loop that you'll need to synchronize?
    for (int candidate = min; candidate < range.max; candidate++) {
        bool is_prime = true;

        // search from 2 to √(n)
        int limit = ceil(sqrt(candidate));
        for (int factor = 2; factor <= limit; factor++) {
            // if divisible, don't increment
            if (candidate % factor == 0) {
                is_prime = false;
                break;
            }
        }

        // if prime, increment counter...?
        if (is_prime) {
            num_primes += 1;
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



    // TODO: convert the primefinding code into a multithreaded version!
    // Divide up the work between the threads. Ensure that no thread
    // performs the same work twice!

    // TODO: is there anything else you'll need to do?

    std::cout << "num_primes: " << num_primes << std::endl;



    // for logging purposes
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /
                     1000000.0
              << "[s] (TOTAL)" << std::endl;
    return 0;
}
