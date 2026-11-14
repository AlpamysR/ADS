#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int s, e;
    cin >> s >> e;
    vector<int> d(n + 1, -1);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u = 1; u <= n; u++)
            if (a[v][u] == 1 && d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
    }
    cout << d[e];
}