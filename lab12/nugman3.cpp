#include <bits/stdc++.h>
using namespace std;

int a[401][401], d[401];

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    int w = !a[1][n];
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u = 1; u <= n; u++)
            if (u != v && a[v][u] == w && d[u] < 0) {
                d[u] = d[v] + 1;
                q.push(u);
            }
    }
    cout << d[n];
}