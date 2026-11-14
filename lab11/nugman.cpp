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
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) p[i] = i;
    vector<int> ans(n + 1, 0);
    int c = 0;
    for (int i = n; i >= 2; i--) {
        c++;
        for (int u : g[i])
            if (u > i) {
                int a = f(i), b = f(u);
                if (a != b) {
                    p[a] = b;
                    c--;
                }
            }
        ans[i - 1] = c;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}