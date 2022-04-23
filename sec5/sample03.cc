#include <stdio.h>
#include <thread>

int main() {
    std::thread threads[3];
    for (int i = 0; i != 3; i++) {
        threads[i] = std::thread(printf, "%d\n", i + 1);
    }

    for (int i = 0; i != 3; i++) {
        threads[i].join();
    }
}
