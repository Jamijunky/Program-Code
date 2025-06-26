#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to compute the sum of squares of differences
int computeSumOfSquares(const vector<int>& interleaved) {
    int sum = 0;
    for (size_t i = 1; i < interleaved.size(); i++) {
        int diff = interleaved[i] - interleaved[i - 1];
        sum += diff * diff;
    }
    return sum;
}

// Function to interleave two vectors
vector<int> interleaveVectors(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result;
    size_t i = 0, j = 0;
    
    // Alternate elements from both vectors
    while (i < v1.size() && j < v2.size()) {
        result.push_back(v1[i++]);
        result.push_back(v2[j++]);
    }
    
    // Append remaining elements from v1
    while (i < v1.size()) {
        result.push_back(v1[i++]);
    }
    
    // Append remaining elements from v2
    while (j < v2.size()) {
        result.push_back(v2[j++]);
    }
    
    return result;
}

int main() {
    int n, m;
    cout<<"Size of V1:";
    cin >> n; // Read size of v1
    vector<int> v1(n);
    for (int i = 0; i < n; i++) cin >> v1[i]; // Read elements of v1
    
    cout<<"Size of V2:";
    cin >>m; // Read size of v2
    vector<int> v2(m);
    for (int i = 0; i < m; i++) cin >> v2[i]; // Read elements of v2

    vector<int> interleaved = interleaveVectors(v1, v2);
    
    // Output interleaved vector
    cout << "Interleaved Vector: ";
    for (int num : interleaved) {
        cout << num << " ";
    }
    cout << endl;

    // Compute and print sum of squares of differences
    int sumOfSquares = computeSumOfSquares(interleaved);
    cout << "Sum: " << sumOfSquares << endl;

    return 0;
}
