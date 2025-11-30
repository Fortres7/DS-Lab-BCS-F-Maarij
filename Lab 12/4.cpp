#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computeLPS(string p) {
    int m = p.length();
    vector<int> lps(m);
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

vector<int> KMPSearch(string t, string p) {
    vector<int> lps = computeLPS(p);
    for (int x : lps) cout << x << " ";
    cout << endl;
    vector<int> ans;
    int i = 0, j = 0, n = t.length(), m = p.length();
    while (i < n) {
        if (t[i] == p[j]) { i++; j++; }
        if (j == m) { ans.push_back(i - j); j = lps[j - 1]; }
        else if (i < n && t[i] != p[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return ans;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";
    vector<int> ans = KMPSearch(text, pattern);
    for (int x : ans) cout << x << " ";

    return 0;
}
