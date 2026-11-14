#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1, INT_MAX);
    while (q--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            if (d[v] == 0) continue;
            d[v] = 0;
            queue<int> qu;
            qu.push(v);
            while (!qu.empty()) {
                int x = qu.front();
                qu.pop();
                for (int u : g[x])
                    if (d[u] > d[x] + 1) {
                        d[u] = d[x] + 1;
                        qu.push(u);
                    }
            }
        } else {
            cout << (d[v] == INT_MAX ? -1 : d[v]) << "\n";
        }
    }
}