#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string b, a;
    cin >> b >> a;
    int m = a.size(), n = b.size();

    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        int k = pi[i - 1];
        while (k > 0 && a[i] != a[k]) k = pi[k - 1];
        if (a[i] == a[k]) k++;
        pi[i] = k;
    }

    vector<int> res;
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && (k == m || b[i] != a[k])) k = pi[k - 1];
        if (b[i] == a[k]) k++;
        if (k == m) res.push_back(i - m + 2);
    }

    cout << res.size() << "\n";
    for (size_t i = 0; i < res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    return 0;
}