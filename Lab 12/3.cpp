#include <iostream>
#include <vector>
#include <string>
using namespace std;

void badCharTable(string p, vector<int> &bad) {
    for (int i = 0; i < 256; i++) bad[i] = -1;
    for (int i = 0; i < p.length(); i++) bad[p[i]] = i;
}

void goodSuffixTable(string p, vector<int> &suff, vector<int> &gs) {
    int m = p.length();
    suff[m - 1] = m;
    int g = m - 1, f = 0;
    for (int i = m - 2; i >= 0; i--) {
        if (i > g && suff[i + m - 1 - f] < i - g) suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g) g = i;
            f = i;
            while (g >= 0 && p[g] == p[g + m - 1 - f]) g--;
            suff[i] = f - g;
        }
    }
    for (int i = 0; i < m; i++) gs[i] = m;
    int j = 0;
    for (int i = m - 1; i >= 0; i--)
        if (suff[i] == i + 1)
            for (; j < m - 1 - i; j++)
                if (gs[j] == m) gs[j] = m - 1 - i;
    for (int i = 0; i <= m - 2; i++)
        gs[m - 1 - suff[i]] = m - 1 - i;
}

vector<int> boyerMoore(string t, string p) {
    int n = t.length(), m = p.length();
    vector<int> bad(256), suff(m), gs(m), ans;
    badCharTable(p, bad);
    goodSuffixTable(p, suff, gs);
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && p[j] == t[s + j]) j--;
        if (j < 0) {
            ans.push_back(s);
            s += gs[0];
        } else {
            int bc = j - bad[t[s + j]];
            int gsShift = gs[j];
            s += max(bc, gsShift);
        }
    }
    return ans;
}

int main() {
    string dna = "ACGTACGTGACG";
    string pat = "ACG";
    vector<int> ans = boyerMoore(dna, pat);
    for (int x : ans) cout << x << " ";

    return 0;
}
