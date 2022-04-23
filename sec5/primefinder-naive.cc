#include <chrono>
#include <cmath>
#include <iostream>

#define MAX_LIMIT 20000000 // primes we are searching for

/**
 * Struct representing an int range.
 */
typedef struct {
    int min;
    int max;
} range_t;

// global counter for primes!
int num_primes = 0;

void count_primes_in_range(range_t range) {
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
            num_primes += 1;
        }
    }
}

int main() {
    // for logging purposes
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();



    // Single-threaded implementation of prime finding.
    count_primes_in_range({0, MAX_LIMIT});
    printf("num primes: %d\n", num_primes);



    // for logging purposes
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed = "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /
                     1000000.0
              << "[s] (TOTAL)" << std::endl;
    return 0;
}
