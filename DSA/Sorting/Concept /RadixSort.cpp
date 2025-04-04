#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int maxdigit(vector<int> &vec) {
    int largest = *max_element(vec.begin(), vec.end());
    int count = 0;
    while (largest > 0) {
        count++;
        largest /= 10;
    }
    return count;
}

void countingSort(vector<int> &vec, int exp) {
    int n = vec.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (vec[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (vec[i] / exp) % 10;
        output[count[digit] - 1] = vec[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        vec[i] = output[i];
    }
}

void radixsort(vector<int> &vec) {
    int maxNum = *max_element(vec.begin(), vec.end());

    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(vec, exp);
    }
}

int main() {
    vector<int> vec;
    int num;
    cout << "Enter numbers (non-integer to stop):\n";

    while (cin >> num) {
        vec.push_back(num);
    }

    radixsort(vec);

    cout << "Sorted Numbers:\n";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
