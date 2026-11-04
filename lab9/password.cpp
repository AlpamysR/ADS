#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    long long K;
    cin >> s >> K >> t;
    int m = s.size(), n = t.size();

    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int k = pi[i - 1];
        while (k > 0 && s[i] != s[k]) k = pi[k - 1];
        if (s[i] == s[k]) k++;
        pi[i] = k;
    }

    long long cnt = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && (k == m || t[i] != s[k])) k = pi[k - 1];
        if (t[i] == s[k]) k++;
        if (k == m) cnt++;
    }

    cout << (cnt >= K ? "YES" : "NO") << "\n";
    return 0;
}