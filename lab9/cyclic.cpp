#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t, a;
    cin >> t >> a;
    int n = t.size();

    string s = t + t;
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int k = pi[i - 1];
        while (k > 0 && a[i] != a[k]) k = pi[k - 1];
        if (a[i] == a[k]) k++;
        pi[i] = k;
    }

    int ans = -1;
    int k = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        while (k > 0 && (k == n || s[i] != a[k])) k = pi[k - 1];
        if (s[i] == a[k]) k++;
        if (k == n) {
            int start = i - n + 1;
            if (start < n) {
                int sh = (n - start) % n;
                if (ans == -1 || sh < ans) ans = sh;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}