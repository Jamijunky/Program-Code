#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int semaphore = 1;   // Binary Semaphore

void wait() {
    while (true) {
        mtx.lock();
        if (semaphore > 0) {
            semaphore--;
            mtx.unlock();
            break;
        }
        mtx.unlock();
    }
}

void signal() {
    mtx.lock();
    semaphore++;
    mtx.unlock();
}

void criticalSection(int id) {

    wait();   // Enter

    cout << "Thread " << id << " is in Critical Section\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Thread " << id << " leaving Critical Section\n";

    signal(); // Exit
}

int main() {

    thread t1(criticalSection, 1);
    thread t2(criticalSection, 2);
    thread t3(criticalSection, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}