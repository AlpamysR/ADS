#include <bits/stdc++.h>
using namespace std;
typedef long long L;
int n, m;
vector<pair<int,int>> g[100001];

vector<L> dij(int s) {
    vector<L> d(n + 1, 1e18);
    priority_queue<pair<L,int>, vector<pair<L,int>>, greater<>> q;
    q.push({d[s] = 0, s});
    while (!q.empty()) {
        auto [w, v] = q.top();
        q.pop();
        if (w > d[v]) continue;
        for (auto [u, c] : g[v])
            if (d[u] > w + c) q.push({d[u] = w + c, u});
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    int s, a, b, f;
    cin >> s >> a >> b >> f;
    auto A = dij(a), B = dij(b);
    L r = min(A[s] + A[b] + B[f], B[s] + B[a] + A[f]);
    cout << (r >= 1e18 ? -1 : r);
}