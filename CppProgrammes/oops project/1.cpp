#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindrome(const string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void longestBalancedPalindrome(const string &s)
{
    int n = s.length();
    int maxLength = 0, startIdx = -1;
    int count0, count1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            count0 = count1 = 0;
            for (int k = i; k <= j; k++)
            {
                if (s[k] == '0')
                    count0++;
                else
                    count1++;
            }
            if (count0 == count1 && isPalindrome(s, i, j))
            {
                if (j - i + 1 > maxLength)
                {
                    maxLength = j - i + 1;
                    startIdx = i;
                }
            }
        }
    }

    if (startIdx != -1)
    {
        string result = s.substr(startIdx, maxLength);
        int ones = count(result.begin(), result.end(), '1');
        cout << "Longest Balanced Palindrome: " << result << endl;
        cout << "Number of 1's: " << ones << endl;
    }
    else
    {
        cout << "No Balanced Palindromic Substring Found" << endl;
    }
}

int main()
{
    string input = "0010110100101";
    longestBalancedPalindrome(input);
    return 0;
}