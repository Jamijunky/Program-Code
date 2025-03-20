#include <iostream>
// circular linked list is also singly and doubly linked
using namespace std;
struct node
{
  int data;
  node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
  node()
  {
    cout << "Enter value: ";
    int a;
    cin >> a;
    data = a;
    next = NULL;
  }
};
int main()
{
  node *head = new node(1);
  node *second = new node(2);
  node *third = new node;
  node *fourth = new node(4);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = head;
  // print list
  node *curr = head;
  for(int i = 0; i < 8; i++)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  return 0;
}