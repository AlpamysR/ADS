#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> a;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] != '1') return;
    a[x][y] = '0';
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '1') {
                cnt++;
                dfs(i, j);
            }
    cout << cnt;
}