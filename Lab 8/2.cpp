#include <iostream>
#include <string>
using namespace std;

class Combatant
{
public:
  string name;
  int healthPoints;
  int attackPower;

  Combatant(string s, int a)
  {
    name = s;
    healthPoints = 100;
    attackPower = a;
  }

  Combatant(const Combatant &obj)
  {
    name = obj.name;
    healthPoints = obj.healthPoints;
    attackPower = obj.attackPower;
  }

  void display()
  {
    cout << "Name: " << name
         << " , Attack Power: " << attackPower
         << " , HP: " << healthPoints << endl;
  }
};

class Node
{
public:
  Combatant *cObj;
  Node *left;
  Node *right;

  Node(const Combatant &obj)
  {
    left = NULL;
    right = NULL;
    cObj = new Combatant(obj);
  }
  int attack(Node *def)
  {
    int attackValue = 5 + def->cObj->attackPower;

    cObj->healthPoints -= attackValue;
    if (cObj->healthPoints < 0)
    {
      cObj->healthPoints = 0;
    }
    return attackValue;
  }
};

class BST
{
public:
  Node *root;

  BST()
  {
    root = NULL;
  }

  Node *insertNode(Node *curr, Combatant &obj)
  {
    if (curr == NULL)
      return new Node(obj);

    if (obj.name > curr->cObj->name)
      curr->right = insertNode(curr->right, obj);
    else if (obj.name < curr->cObj->name)
      curr->left = insertNode(curr->left, obj);

    return curr;
  }

  void insertN(Combatant &obj)
  {
    root = insertNode(root, obj);
  }

  Node *returnBST()
  {
    Node *temp = root;
    if (temp == NULL)
      return NULL;

    while (temp->left != NULL)
      temp = temp->left;

    return temp;
  }

  Node *deleteMin(Node *node)
  {
    if (node == NULL)
      return NULL;

    if (node->left == NULL)
    {
      Node *rightChild = node->right;
      delete node;
      return rightChild;
    }
    node->left = deleteMin(node->left);
    return node;
  }

  void deleteBST()
  {
    root = deleteMin(root);
  }

  void inOrder(Node *curr)
  {
    if (curr == NULL)
      return;

    inOrder(curr->left);
    curr->cObj->display();
    inOrder(curr->right);
  }

  void display()
  {
    inOrder(root);
  }
};

int main()
{
  BST enemy;
  BST player;

  Combatant c1("Rafay", 20);
  Combatant c2("Ali", 30);
  Combatant c3("Saim", 20);
  Combatant c4("Maarij", 40);
  Combatant c5("Sameed", 50);
  Combatant c6("Ammaar", 40);

  player.insertN(c1);
  player.insertN(c2);
  player.insertN(c3);

  enemy.insertN(c4);
  enemy.insertN(c5);
  enemy.insertN(c6);

  bool flag = true;
  int round = 0;

  Node *attacker = player.returnBST();
  Node *defender = enemy.returnBST();

  while (flag)
  {
    round++;
    cout << "Round " << round << endl;

    cout << "Player Team:\n";
    player.display();

    cout << "Enemy Team:\n";
    enemy.display();

    cout << "Attacker: " << attacker->cObj->name
         << "\nDefender: " << defender->cObj->name << endl;

    int value = attacker->attack(defender);
    cout << "Attack Value : " << value << endl;

    cout << "Attacker: " << defender->cObj->name
         << "\nDefender: " << attacker->cObj->name << endl;

    int value2 = defender->attack(attacker);
    cout << "Attack Value : " << value2 << endl;

    cout << "Updated HP's:\n"
         << attacker->cObj->name << ": " << attacker->cObj->healthPoints
         << "\n"
         << defender->cObj->name << ": " << defender->cObj->healthPoints;

    if (attacker->cObj->healthPoints == 0)
    {
      cout << endl
           << attacker->cObj->name << " was Defeated\n";
      player.deleteBST();
      attacker = player.returnBST();

      if (attacker == NULL)
      {
        cout << "Enemy Team Won\n";
        break;
      }
    }

    if (defender->cObj->healthPoints == 0)
    {
      cout << endl
           << defender->cObj->name << " was Defeated\n";
      enemy.deleteBST();
      defender = enemy.returnBST();

      if (defender == NULL)
      {
        cout << "Player Team Won\n";
        break;
      }
    }

    cout << "\n\n";
  }
}
