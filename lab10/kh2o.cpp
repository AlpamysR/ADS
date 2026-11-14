#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (a[x][y] && a[y][z] && a[x][z]) cout << "YES\n";
        else cout << "NO\n";
    }
}