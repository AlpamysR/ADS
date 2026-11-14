#include <bits/stdc++.h>
using namespace std;

int p[200005];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<long long, 3>> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i][1] >> s[i][2] >> s[i][0];
    }
    sort(s.begin(), s.end());
    for (int i = 1; i <= n + 1; i++) p[i] = i;
    long long ans = 0;
    for (auto &e : s) {
        int l = e[1], r = e[2];
        for (int i = f(l); i < r; i = f(i)) {
            ans += e[0];
            p[i] = i + 1;
        }
    }
    cout << ans;
}