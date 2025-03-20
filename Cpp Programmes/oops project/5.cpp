#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int countVowels(const string& word) {
    int count = 0;
    for (char ch : word) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

string reverseWord(const string& word) {
    string reversed = word;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

int main() {
    string sentence;
    getline(cin, sentence);
    stringstream ss(sentence);
    string firstWord, lastWord, word;
    
    ss >> firstWord; 
    
    while (ss >> word) { 
        lastWord = word;
    }

    if (lastWord.empty()) {
        lastWord = firstWord; 
    }

    if (lastWord == reverseWord(firstWord)) {
        int vowelCount = countVowels(firstWord);
        cout << "Valid with " << vowelCount << " vowels" << endl;
    } else {
        cout << "Invalid Stringtopian Sentence" << endl;
    }

    return 0;
}
