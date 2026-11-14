#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> in(n + 1, 0);
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        g[i].push_back(j);
        in[j]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) q.push(i);
    vector<int> r;
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        r.push_back(x);
        for (int u : g[x])
            if (--in[u] == 0) q.push(u);
    }
    if ((int)r.size() < n) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    for (int x : r) cout << x << " ";
}