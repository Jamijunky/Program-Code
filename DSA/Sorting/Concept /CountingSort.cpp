#include <iostream>
#include <vector>

using namespace std;
vector<int> countingsort(vector<int> &inputVec)
{
  vector<int> outputVec(inputVec.size());
  int largest = inputVec[0];
  for (int i = 1; i < inputVec.size(); i++)
  {
    if (inputVec[i] > largest)
    {
      largest = inputVec[i];
    }
  }
  vector<int> countVec(largest + 1, 0);
  for (int num : inputVec)
  {
    countVec[num]++;
  }
  for (int i = 1; i <= largest; i++)
  {
    countVec[i] += countVec[i - 1];
  }
  for (int i = 0; i < inputVec.size(); i++)
  {
    outputVec[countVec[inputVec[i]] - 1] = inputVec[i];
    countVec[inputVec[i]]--;
  }

  return outputVec;
}

int main()
{
  vector<int> inputVec;
  int num;
  cout << "Enter the Array\nInput anything except number to come out of input loop\n";
  while (cin >> num)
  {
    inputVec.push_back(num);
  }
  vector<int> outputVec = countingsort(inputVec);
  for (int v : outputVec)
  {
    cout << v << " ";
  }
  return 0;
}