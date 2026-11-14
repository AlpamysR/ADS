#include <bits/stdc++.h>
using namespace std;

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
    vector<int> par(n + 1, 0), ch(n + 1, 0);
    vector<bool> vis(n + 1, false);
    int ans = 0;
    for (int s = 1; s <= n; s++) {
        if (vis[s]) continue;
        ans++;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int u : g[x])
                if (!vis[u]) {
                    vis[u] = true;
                    par[u] = x;
                    q.push(u);
                }
        }
    }
    for (int v = 1; v <= n; v++)
        ch[v] = g[v].size() - (par[v] ? 1 : 0);
    for (int v = 1; v <= n; v++)
        if (par[v] && ch[v] > ch[par[v]]) ans++;
    cout << ans;
}