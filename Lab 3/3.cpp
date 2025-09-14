#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtTail(Node *&tail, int d)
{
  Node *temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *ReverseinK(Node *head, int k)
{

  if (head == NULL)
  {
    return NULL;
  }
  Node *next = NULL;
  Node *curr = head;
  Node *prev = NULL;
  int count = 0;

  while (curr != NULL && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }

  if (next != NULL)
  {
    head->next = ReverseinK(next, k);
  }
  return prev;
}

int main()
{

  cout << "Enter number of elements: ";
  int n;
  cin >> n;
  int num;

  cout << "Enter element#1: ";
  cin >> num;
  Node *node1 = new Node(num);
  Node *head = node1;
  Node *tail = node1;
  for (int i = 1; i < n; i++)
  {
    cout << "Enter element#" << i + 1 << ": ";
    cin >> num;
    insertAtTail(tail, num);
  }
  print(head);

  cout << "Enter K: ";
  int k;
  cin >> k;

  head = ReverseinK(head, k);
  print(head);  

  return 0;
}
