#include <iostream>

using namespace std;

char switchchar(char expected)
{
  if (expected == '0')
    return '1';
  return '0';
}

int stringtomakealternate(string &str, char expected)
{
  int flipcount = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] != expected)
    {
      flipcount++;
      str[i] = expected;
    }
    expected = switchchar(expected);
  }
  return flipcount;
}

int count(string &str)
{
  string str0 = str;
  string str1 = str;
  int changes0 = stringtomakealternate(str0, '0');
  int changes1 = stringtomakealternate(str1, '1');
  if (changes0 >= changes1)
  {
    return changes1;
  }
  else
  {
    return changes0;
  }
}
string tostring(string &str)
{
  string str0 = str;
  string str1 = str;
  int changes0 = stringtomakealternate(str0, '0');
  int changes1 = stringtomakealternate(str1, '1');
  if (changes0 >= changes1)
  {
    return str1;
  }
  else
  {
    return str0;
  }
}

int main()
{
  string str;
  cout << "Enter a string: ";
  cin >> str;
  int total_changes = count(str);
  cout << "Minimum number of changes required to make the string alternate: " << total_changes << endl;
  cout << "Final string: " << tostring(str) << endl;

  return 0;
}