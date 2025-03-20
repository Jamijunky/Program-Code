#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
  node *previous;
  node(int x)
  {
    data = x;
    next = NULL;
    previous = NULL;
  }
  node()
  {
    cout << "Enter value: ";
    int a;
    cin >> a;
    data = a;
    next = NULL;
    previous = NULL;
  }
};

void normal_list(node *curr)
{
  if (curr == NULL)
  {
    return;
  }
  cout << curr->data << " ";
  normal_list(curr->next);
}

void reverse_list(node *curr)
{

  while (curr != NULL)
  {
    cout << curr->data << " ";
    curr = curr->previous;
  }
}
int main()
{
  node *head = new node(23);
  node *second = new node(2);
  node *third = new node(3);
  node *fourth = new node;
  node *insert = new node(25);

  head->next = second;
  second->previous = head;
  second->next = insert;
  insert->previous = second;
  insert->next = third;
  third->previous = insert;
  third->next = fourth;
  fourth->previous = third;
  normal_list(head);

  cout << "\nReverse list.....\n";
  reverse_list(fourth);

  return 0;
}