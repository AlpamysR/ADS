#include <bits/stdc++.h>
using namespace std;

int d[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int k = 0; k < n; k++) {
        int v = x[k];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][v] + d[v][j]);
        int mx = 0;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++)
                mx = max(mx, d[x[i]][x[j]]);
        cout << mx << "\n";
        
    }
}