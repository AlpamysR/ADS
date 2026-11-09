#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    string t;
    t.reserve(n + m + n);
    while ((int)t.size() < m + n - 1) t += a;

    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int k = pi[i - 1];
        while (k > 0 && b[i] != b[k]) k = pi[k - 1];
        if (b[i] == b[k]) k++;
        pi[i] = k;
    }

    int k = 0;
    for (int i = 0; i < (int)t.size(); i++) {
        while (k > 0 && (k == m || t[i] != b[k])) k = pi[k - 1];
        if (t[i] == b[k]) k++;
        if (k == m) {
            int start = i - m + 1;
            long long ans = (start + m + n - 1) / n;
            cout << ans << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}