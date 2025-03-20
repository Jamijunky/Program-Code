#include <iostream>     // cin, cout
#include <iomanip>      // setprecision, setw
#include <string>       // std::string
#include <cmath>        // sqrt, pow, sin, cos, tan, abs, ceil, floor, log
#include <cstdlib>      // rand, srand, abs, atoi, atof, exit
#include <vector>       // vector
#include <array>        // array
#include <deque>        // deque
#include <list>         // list
#include <stack>        // stack
#include <queue>        // queue
#include <set>          // set
#include <map>          // map
#include <fstream>      // ifstream, ofstream, fstream
#include <sstream>      // stringstream
#include <algorithm>    // sort, reverse, max_element, min_element, binary_search
#include <utility>      // pair, swap, make_pair
#include <numeric>      // accumulate, gcd, lcm
#include <thread>       // thread, sleep_for
#include <chrono>       // chrono, sleep_for
#include <memory>       // unique_ptr, shared_ptr, make_shared
#include <cstdio>       // printf, scanf
#include <cstring>      // strcpy, strlen, strcmp
#include <cctype>       // toupper, tolower, isdigit, isalpha

using namespace std;

int main() {
    // ✅ Input / Output
    cout << "Enter a number: ";
    int num;
    cin >> num;
    cout << "You entered: " << num << endl;

    // ✅ String Functions
    string str = "Hello";
    str.append(" World");
    cout << str << " | Length: " << str.length() << " | Substring: " << str.substr(0, 5) << endl;

    // ✅ Math Functions
    cout << "sqrt(25): " << sqrt(25) << ", pow(2,3): " << pow(2,3) << endl;
    cout << "ceil(3.4): " << ceil(3.4) << ", floor(3.9): " << floor(3.9) << endl;

    // ✅ Random Number
    srand(time(0));  // Seed random generator
    cout << "Random number: " << rand() % 100 << endl;

    // ✅ Vector (Dynamic Array)
    vector<int> v = {3, 1, 4, 2};
    sort(v.begin(), v.end());
    cout << "Sorted Vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // ✅ Stack (LIFO)
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << "Stack Top: " << s.top() << endl; 
    s.pop();

    // ✅ Queue (FIFO)
    queue<int> q;
    q.push(5);
    q.push(10);
    cout << "Queue Front: " << q.front() << endl;
    q.pop();

    // ✅ Set (Unique Elements)
    set<int> mySet = {5, 1, 3};
    mySet.insert(4);
    cout << "Set contains: ";
    for (int x : mySet) cout << x << " ";
    cout << endl;

    // ✅ Map (Key-Value Pair)
    map<string, int> age;
    age["Alice"] = 25;
    cout << "Alice's age: " << age["Alice"] << endl;

    // ✅ File Handling
    ofstream fout("test.txt");
    fout << "Hello File!" << endl;
    fout.close();
    ifstream fin("test.txt");
    string line;
    getline(fin, line);
    cout << "File Content: " << line << endl;

    // ✅ Sorting & Algorithms
    int arr[] = {10, 5, 8};
    sort(arr, arr + 3);
    cout << "Min Element: " << *min_element(arr, arr + 3) << endl;

    // ✅ Threads (Multithreading)
    thread t([]() {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Thread Done!" << endl;
    });
    t.join();

    // ✅ Smart Pointers (Memory Management)
    unique_ptr<int> ptr = make_unique<int>(42);
    cout << "Unique Pointer: " << *ptr << endl;

    return 0;
}
