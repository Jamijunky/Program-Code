#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if two words are anagrams
bool areAnagrams(string word1, string word2) {
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    return word1 == word2;
}

// Function to check if the mystical path is cleared
bool isMysticalPathCleared(const vector<string>& words) {
    for (size_t i = 1; i < words.size(); i++) {
        if (!areAnagrams(words[i - 1], words[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout<<"No of words: ";
    cin >> n; // Number of words
    vector<string> words(n);
cout<<"Enter the words: ";
    for (int i = 0; i < n; i++) {
        cin >> words[i]; // Read words
    }

    if (isMysticalPathCleared(words)) {
        cout << "Mystical Path Cleared" << endl;
    } else {
        cout << "Path Blocked" << endl;
    }

    return 0;
}
