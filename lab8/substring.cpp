#include <bits/stdc++.h>
using namespace std;

short lcp[2002][2002];
int cnt[2002][2002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int q;
    cin >> s >> q;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            lcp[i][j] = (s[i] == s[j]) ? lcp[i + 1][j + 1] + 1 : 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cnt[i][lcp[i][j]]++;
        for (int len = n - 1; len >= 1; len--)
            cnt[i][len] += cnt[i][len + 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << cnt[l][r - l] << '\n';
    }
}