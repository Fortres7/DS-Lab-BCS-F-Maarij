#include <iostream>
#include <queue>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

Node *insertBST(Node *root, int key)
{
  if (root == NULL)
  {
    return new Node(key);
  }
  if (key < root->data)
  {
    root->left = insertBST(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = insertBST(root->right, key);
  }
  return root;
}


void inorder(Node *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void preorder(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
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
    cout << curr->data << " ";
    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }
}

bool searchBST(Node *root, int key)
{
  if (root == NULL)
    return false;
  if (root->data == key)
    return true;
  else if (key < root->data)
    return searchBST(root->left, key);
  else
    return searchBST(root->right, key);
}


Node *findMin(Node *root)
{
  while (root && root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

Node *deleteBST(Node *root, int key)
{
  if (root == NULL)
    return root;

  if (key < root->data)
  {
    root->left = deleteBST(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = deleteBST(root->right, key);
  }
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
    root->right = deleteBST(root->right, temp->data);
  }
  return root;
}




int main()
{
  Node *root = NULL;

  int values[] = {50, 30, 70, 20, 40, 60, 80};
  for (int i = 0; i < 7; i++)
  {
    root = insertBST(root, values[i]);
  }

  cout << "Inorder Traversal (sorted): ";
  inorder(root);
  cout << endl;

  cout << "Preorder Traversal: ";
  preorder(root);
  cout << endl;

  cout << "Postorder Traversal: ";
  postorder(root);
  cout << endl;

  cout << "Level Order Traversal: ";
  levelOrder(root);
  cout << endl;

  int key = 60;
  cout << "Search " << key << ": ";
  cout << (searchBST(root, key) ? "Found" : "Not Found") << endl;

  root = deleteBST(root, 20);
  cout << "After deleting 20 (Inorder): ";
  inorder(root);
  return 0;
}
