#include <iostream>
using namespace std;


int Bruteforce(string text, string s)
{
  int n = text.length();
  int m = s.length();

  for (int i = 0; i < n - m; i++)
  {

    int j = 0;
    while (j < m && text[i + j] == s[j])
    {
      j++;
    }
    if (j == m)
    {
      cout << i << " ";
    }
  }
}


int main()
{
  string txt = "the quick brown fox jumps over the lazy dog";
  string s = "the";
  cout << "Found!\nIndex: ";
  Bruteforce(txt, s);

  return 0;
}
