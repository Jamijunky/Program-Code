#include <iostream>
#include <string>
using namespace std;

string numToWords(int n) {
    string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                     "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                     "sixteen", "seventeen", "eighteen", "nineteen"};

    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
                     "seventy", "eighty", "ninety"};

    if (n == 1000)
        return "onethousand";
    else if (n >= 100) {
        int rem = n % 100;
        string result = ones[n / 100] + "hundred";
        if (rem != 0)
            result += "and" + numToWords(rem);
        return result;
    }
    else if (n >= 20)
        return tens[n / 10] + ones[n % 10];
    else
        return ones[n];
}

int main() {
    int total = 0;
    for (int i = 1; i <= 1000; i++) {
        string word = numToWords(i);
        total += word.length();
    }
    cout << "Total letters used: " << total << endl;
    return 0;
}
