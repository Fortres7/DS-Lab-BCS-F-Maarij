#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  int height;

  Node(int val)
  {
    data = val;
    left = right = NULL;
    height = 1;
  }
};

class AVL
{
  Node *root;

  int get_height(Node *node)
  {
    if (node == NULL)
      return 0;
    return node->height;
  }

  int get_balance(Node *node)
  {
    if (node == NULL)
      return 0;
    return get_height(node->left) - get_height(node->right);
  }

  void update_height(Node *node)
  {
    int l_h = get_height(node->left);
    int r_h = get_height(node->right);
    node->height = 1 + max(l_h, r_h);
  }

  Node *rotate_right(Node *y)
  {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    update_height(y);
    update_height(x);

    return x;
  }

  Node *rotate_left(Node *x)
  {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    update_height(x);
    update_height(y);

    return y;
  }

  Node *balance_node(Node *node)
  {
    int balance = get_balance(node);

    if (balance > 1 && get_balance(node->left) >= 0)
      return rotate_right(node);

    if (balance > 1 && get_balance(node->left) < 0)
    {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }

    if (balance < -1 && get_balance(node->right) <= 0)
      return rotate_left(node);

    if (balance < -1 && get_balance(node->right) > 0)
    {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }

    return node;
  }

  Node *insert(Node *node, int val)
  {
    if (node == NULL)
      return new Node(val);

    if (val < node->data)
      node->left = insert(node->left, val);
    else if (val > node->data)
      node->right = insert(node->right, val);
    else
      return node;

    update_height(node);
    return balance_node(node);
  }

  void inorder_store(Node *node, int arr[], int &idx)
  {
    if (node != NULL)
    {
      inorder_store(node->left, arr, idx);
      arr[idx++] = node->data;
      inorder_store(node->right, arr, idx);
    }
  }

  int get_total_nodes(Node *node)
  {
    if (node == NULL)
      return 0;
    return 1 + get_total_nodes(node->left) + get_total_nodes(node->right);
  }

public:
  AVL()
  {
    root = NULL;
  }

  void insert(int val)
  {
    root = insert(root, val);
  }

  void display()
  {
    inorder(root);
    cout << endl;
  }

  void inorder(Node *node)
  {
    if (node != NULL)
    {
      inorder(node->left);
      cout << node->data << " ";
      inorder(node->right);
    }
  }

  void printRootHeights()
  {
    if (root == NULL)
    {
      cout << "Tree is empty\n";
      return;
    }

    cout << "Root Key: " << root->data << endl;
    cout << "Left Subtree Height: " << get_height(root->left) << endl;
    cout << "Right Subtree Height: " << get_height(root->right) << endl;
  }

  void findKthSmallest(int k)
  {
    int total = get_total_nodes(root);
    if (k < 1 || k > total)
    {
      cout << k << " is invalid\n";
      return;
    }

    int *arr = new int[total];
    int idx = 0;
    inorder_store(root, arr, idx);

    cout << k << "th Smallest = " << arr[k - 1] << endl;

    delete[] arr;
  }

  void findKthLargest(int k)
  {
    int total = get_total_nodes(root);
    if (k < 1 || k > total)
    {
      cout << k << " is invalid\n";
      return;
    }

    int *arr = new int[total];
    int idx = 0;
    inorder_store(root, arr, idx);

    cout << k << "th Largest = " << arr[total - k] << endl;

    delete[] arr;
  }
};

int main()
{
  AVL tree;

  tree.insert(50);
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);
  tree.insert(60);
  tree.insert(80);
  tree.insert(55);
  tree.insert(10);

  cout << "Inorder Traversal: ";
  tree.display();

  cout << "\nRoot Heights:\n";
  tree.printRootHeights();

  tree.findKthSmallest(3);
  tree.findKthLargest(2);

  return 0;
}
