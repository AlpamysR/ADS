#include <bits/stdc++.h>
using namespace std;

int p[1001];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<array<int, 3>> e;
    for (int i = 0; i < m; i++) {
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        int w;
        if (s == "big") w = x;
        else if (s == "small") w = y;
        else w = min(x, y);
        e.push_back({w * c, a, b});
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) p[i] = i;
    long long ans = 0;
    for (auto &t : e) {
        int a = f(t[1]), b = f(t[2]);
        if (a != b) {
            p[a] = b;
            ans += t[0];
        }
    }
    cout << ans;
}