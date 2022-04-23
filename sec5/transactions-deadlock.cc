#include <iostream>
#include <mutex>
#include <random>
#include <stdio.h>
#include <thread>
#include <vector>

#define N_USERS 10

static int next_id = 1;
class User {
  public:
    User(double balance) {
        this->id = next_id;
        this->bal = balance;
        next_id += 1;
    }

    bool transfer_to(User *other, double amt) {
        if (amt > this->bal) {
            return false;
        }
        printf("[Old] U%u bal: $%.2f\tU%u bal: $%.2f\n", this->id, other->bal, other->id,
               other->bal);
        this->bal -= amt;
        other->bal += amt;
        printf("[New] U%u bal: $%.2f\tU%u bal: $%.2f\n", this->id, this->bal, other->id,
               other->bal);
        return true;
    }

    int id;
    double bal;
    std::mutex m;
};

void transfer_many_times(User *sender, std::vector<User *> *users) {
    for (int i = 0; i < 10000; i++) {
        int rand_id = rand() % N_USERS;
        while (rand_id == sender->id) {
            rand_id = rand() % N_USERS;
        }

        User *other = users->at(rand_id);

        sender->m.lock();
        other->m.lock();

        sender->transfer_to(other, 1);

        other->m.unlock();
        sender->m.unlock();
    }
}

int main() {
    std::vector<User *> users(N_USERS);
    std::vector<std::thread> threads(N_USERS);

    for (int i = 0; i < N_USERS; i++) {
        users[i] = new User(1000);
    }

    for (int i = 0; i < N_USERS; i++) {
        threads[i] = std::thread(transfer_many_times, users[i], &users);
    }
    for (int i = 0; i < N_USERS; i++) {
        threads[i].join();
    }

    double final_bal = 0;
    for (int i = 0; i < N_USERS; i++) {
        printf("User %d's balance: %f\n", users[i]->id, users[i]->bal);
        final_bal += users[i]->bal;
        delete users[i];
    }

    printf("Final balance: %f\n", final_bal);
}
