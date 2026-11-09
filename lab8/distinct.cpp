#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    getline(cin, s);
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' '))
        s.pop_back();
    int n = s.size();
    ll ans = 0;
    for (int len = 1; len <= n; len++) {
        string u = s.substr(0, len);
        reverse(u.begin(), u.end());
        int m = len;
        vector<int> z(m, 0);
        int mx = 0;
        for (int i = 1, l = 0, r = 0; i < m; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < m && u[z[i]] == u[i + z[i]]) z[i]++;
            if (i + z[i] > r) l = i, r = i + z[i];
            mx = max(mx, z[i]);
        }
        ans += m - mx;
    }
    cout << ans << endl;
}