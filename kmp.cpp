#include <bits/stdc++.h>
using namespace std;

int find(string str, string pattern, vector<int> v, int m, int n) {
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (str[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = v[j - 1];
            } else {
                i++;
            }
        }
    }
    if (j == m) {
        return true;
    }
    return false; // Return false if pattern not found
}

void change(vector<int>& v, int m, string pat) {
    int i = 1, j = 0;
    while (i < m) {
        if (pat[i] == pat[j]) {
            v[i] = j + 1;
            i++;
            j++;
        } else if (pat[i] != pat[j] && j != 0) {
            j = v[j - 1];
        } else {
            i++;
        }
    }
}

int main() {
    string str = "abcxabcdabcdabcy";
    string pat = "abcdabcy";
    int n = str.size();
    int m = pat.size();
    vector<int> pattern_match(m, 0);
    change(pattern_match, m, pat);
    int ans = find(str, pat, pattern_match, m, n);
    cout << ans << endl;
    return 0;
}
