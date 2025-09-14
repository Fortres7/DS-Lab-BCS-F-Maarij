#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

class LinkedList
{
public:
  Node *head;

  LinkedList()
  {
    head = NULL;
  }
  void append(int value)
  {
    Node *newNode = new Node(value);
    if (head == NULL)
    {
      head = newNode;
      return;
    }

    Node *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
  }
};
Node *convertToDoubly(Node *head)
{
  Node *current = head;
  Node *last = NULL;

  while (current != NULL)
  {
    current->prev = last;
    last = current;
    current = current->next;
  }

  return head;
}
Node *convertToCircular(Node *head)
{
  if (head == NULL)
    return NULL;

  Node *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = head; 
  return head;
}

int main()
{
  LinkedList list1, list2;

  for (int i = 1; i <= 5; i++)
  {
    list1.append(i);
    list2.append(i);
  }

  Node *doublyHead = convertToDoubly(list1.head);
  cout << "Doubly Linked List: ";
  Node *current = doublyHead;
  while (current != NULL)
  {
    cout << current->data;
    if (current->next != NULL)
      cout << " ";
    current = current->next;
  }
  cout << endl;

  Node *circularHead = convertToCircular(list2.head);
  cout << "Circular Linked List: ";
  current = circularHead;
  int count = 0;
  while (count < 6)
  {
    cout << current->data;
    if (count < 5)
      cout << " ";
    current = current->next;
    count++;
  }
  cout << endl;

  return 0;
}
