#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

const int CHAIRS = 3;

int waiting = 0;

mutex mtx;
condition_variable customerCV, barberCV;

/* Barber Thread */
void barber() {

    while (true) {

        unique_lock<mutex> lock(mtx);

        // Sleep if no customers
        while (waiting == 0) {
            cout << "Barber is sleeping...\n";
            customerCV.wait(lock);
        }

        // Take a customer
        waiting--;
        cout << "Barber is cutting hair. Waiting: "
             << waiting << endl;

        barberCV.notify_one();
        lock.unlock();

        // Cutting hair
        this_thread::sleep_for(chrono::seconds(2));

        cout << "Barber finished cutting.\n";
    }
}

/* Customer Thread */
void customer(int id) {

    unique_lock<mutex> lock(mtx);

    if (waiting < CHAIRS) {

        waiting++;
        cout << "Customer " << id
             << " is waiting. Waiting: "
             << waiting << endl;

        customerCV.notify_one();

        // Wait for barber
        barberCV.wait(lock);

        cout << "Customer " << id
             << " is getting haircut.\n";

    } else {

        cout << "Customer " << id
             << " left (No chair).\n";
    }
}

int main() {

    thread b(barber);

    vector<thread> customers;

    for (int i = 1; i <= 10; i++) {

        customers.push_back(thread(customer, i));

        this_thread::sleep_for(
            chrono::milliseconds(700)
        );
    }

    for (auto &c : customers)
        c.join();

    b.join();

    return 0;
}