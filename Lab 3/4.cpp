#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = NULL;
  }
};

class CircularList
{
public:
  Node *head;

  CircularList()
  {
    head = NULL;
  }

  void insert(int value)
  {
    Node *newNode = new Node(value);
    if (head == NULL)
    {
      head = newNode;
      newNode->next = head;
      return;
    }

    Node *current = head;
    while (current->next != head)
    {
      current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
  }

  void print()
  {
    if (head == NULL)
      return;

    Node *temp = head;
    do
    {
      cout << temp->data;
      temp = temp->next;
      if (temp != head)
        cout << " -> ";
    } while (temp != head);
    cout << endl;
  }
};

int Josephus(Node *head, int k)
{
  Node *current = head;
  Node *prev = NULL;

  while (current->next != current)
  {
    for (int count = 1; count < k; count++)
    {
      prev = current;
      current = current->next;
    }
    prev->next = current->next;
    delete current;
    current = prev->next;
  }

  return current->data;
}

int main()
{
  int n, k;
  CircularList clist;

  cout << "Enter number of people: ";
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    clist.insert(i);
  }

  cout << "Enter K: ";
  cin >> k;

  int safePosition = Josephus(clist.head, k);
  cout << "The safe position is: " << safePosition << endl;

  return 0;
}
