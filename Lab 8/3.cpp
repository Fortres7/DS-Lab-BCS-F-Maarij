#include <iostream>
#include <queue>
using namespace std;

class Student
{
public:
  string name;
  int roll;
  int score;

  Student() {}

  Student(string n, int r, int s)
  {
    name = n;
    roll = r;
    score = s;
  }
};

struct Node
{
  Student data;
  Node *left;
  Node *right;

  Node(Student s)
  {
    data = s;
    left = right = NULL;
  }
};

Node *insertBST(Node *root, Student s)
{
  if (root == NULL)
    return new Node(s);

  if (s.name < root->data.name)
    root->left = insertBST(root->left, s);
  else if (s.name > root->data.name)
    root->right = insertBST(root->right, s);

  return root;
}

void levelOrder(Node *root)
{
  if (root == NULL)
    return;

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();

    cout << curr->data.name << " (Roll: " << curr->data.roll
         << ", Score: " << curr->data.score << ")  ";

    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }
}

bool searchBST(Node *root, string name)
{
  if (root == NULL)
    return false;

  if (root->data.name == name)
    return true;

  if (name < root->data.name)
    return searchBST(root->left, name);
  else
    return searchBST(root->right, name);
}

Node *findMin(Node *root)
{
  while (root && root->left != NULL)
    root = root->left;
  return root;
}

Node *deleteByName(Node *root, string name)
{
  if (root == NULL)
    return root;

  if (name < root->data.name)
    root->left = deleteByName(root->left, name);
  else if (name > root->data.name)
    root->right = deleteByName(root->right, name);
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    else if (root->left == NULL)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    Node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteByName(root->right, temp->data.name);
  }
  return root;
}

Node *deleteLowScore(Node *root)
{
  if (root == NULL)
    return NULL;

  root->left = deleteLowScore(root->left);
  root->right = deleteLowScore(root->right);

  if (root->data.score < 10)
    return deleteByName(root, root->data.name);

  return root;
}

Student findMaxScore(Node *root)
{
  if (!root)
    return Student("", 0, -1);

  Student left = findMaxScore(root->left);
  Student right = findMaxScore(root->right);
  Student curr = root->data;

  Student best = curr;

  if (left.score > best.score)
    best = left;
  if (right.score > best.score)
    best = right;

  return best;
}

int main()
{
  Node *root = NULL;

  Student arr[10] = {
      Student("Ahmed", 1, 50), Student("Aammar", 2, 5),
      Student("Hassan", 3, 70), Student("Sara", 4, 20),
      Student("Hassaan", 5, 40), Student("Ali", 6, 2),
      Student("Taimoor", 7, 100), Student("Kamran", 8, 60),
      Student("Saim", 9, 80), Student("Areeb", 10, 9)};

  for (int i = 0; i < 10; i++)
    root = insertBST(root, arr[i]);

  cout << "\nLevel Order Traversal:\n";
  levelOrder(root);
  cout << "\n";
  string key = "Hassaan";
  cout << "\nSearching for " << key << ": "
       << (searchBST(root, key) ? "Found" : "Not Found") << endl;

  root = deleteLowScore(root);
  cout << "\nAfter Deleting Students with Score < 10:\n";
  levelOrder(root);
  cout << "\n";

  Student top = findMaxScore(root);
  cout << "\nStudent With Max Score:\n";
  cout << top.name << " (Roll: " << top.roll << ", Score: " << top.score << ")\n";

  return 0;
}
