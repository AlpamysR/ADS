#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> in(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
    }
    for (int v = 1; v <= n; v++) {
        if (in[v] == 0) continue;
        vector<int> d = in;
        d[v]--;
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (d[i] == 0) q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            cnt++;
            for (int u : g[x])
                if (--d[u] == 0) q.push(u);
        }
        if (cnt == n) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}