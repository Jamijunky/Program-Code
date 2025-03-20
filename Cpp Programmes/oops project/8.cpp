#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to parse input and return a vector of integers
vector<int> parseSequence(const string& input) {
    vector<int> sequence;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        sequence.push_back(num);
    }
    return sequence;
}

// Function to check if a sequence is strictly decreasing
bool isStrictlyDecreasing(const vector<int>& sequence) {
    for (size_t i = 1; i < sequence.size(); i++) {
        if (sequence[i] >= sequence[i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if the runes can be reordered to fulfill the requirements
bool canUnlockVault(vector<int>& tower1, vector<int>& tower2, vector<int>& tower3) {
    // Calculate original tower sums
    int sum1 = accumulate(tower1.begin(), tower1.end(), 0);
    int sum2 = accumulate(tower2.begin(), tower2.end(), 0);
    int sum3 = accumulate(tower3.begin(), tower3.end(), 0);

    // Find the tallest tower (one with the max sum)
    int maxSum = max({sum1, sum2, sum3});

    // Sort towers in descending order
    sort(tower1.rbegin(), tower1.rend());
    sort(tower2.rbegin(), tower2.rend());
    sort(tower3.rbegin(), tower3.rend());

    // Check if all towers are now strictly decreasing
    if (!isStrictlyDecreasing(tower1) || !isStrictlyDecreasing(tower2) || !isStrictlyDecreasing(tower3)) {
        return false;
    }

    // Ensure no tower exceeds the original tallest tower's sum
    if (accumulate(tower1.begin(), tower1.end(), 0) > maxSum ||
        accumulate(tower2.begin(), tower2.end(), 0) > maxSum ||
        accumulate(tower3.begin(), tower3.end(), 0) > maxSum) {
        return false;
    }

    return true;
}

int main() {
    string input1, input2, input3;
    getline(cin, input1, ',');
    getline(cin, input2, ',');
    getline(cin, input3);

    vector<int> tower1 = parseSequence(input1);
    vector<int> tower2 = parseSequence(input2);
    vector<int> tower3 = parseSequence(input3);

    if (canUnlockVault(tower1, tower2, tower3)) {
        cout << "Vault Unlocked" << endl;
    } else {
        cout << "Vault Sealed" << endl;
    }

    return 0;
}
