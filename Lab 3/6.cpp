#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *child;

  Node(int value)
  {
    data = value;
    next = nullptr;
    child = nullptr;
  }
};

Node *flattenList(Node *head)
{
  if (head == nullptr)
    return nullptr;

  Node *current = head;

  while (current != nullptr)
  {
    if (current->child != nullptr)
    {
      Node *nextNode = current->next;
      current->next = current->child;
      current->child = nullptr;

      Node *tail = current->next;
      while (tail->next != nullptr)
      {
        tail = tail->next;
      }

      tail->next = nextNode;
    }

    current = current->next;
  }

  return head;
}

int main()
{
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);
  node1->next = node2;
  node2->next = node3;
  node2->child = node4;
  node4->next = node5;
  Node *result = flattenList(node1);

  cout << "Flattened list: ";
  Node *temp = result;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;

  return 0;
}
