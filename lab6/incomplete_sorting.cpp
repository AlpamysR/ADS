#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int j = 0; j < m; j++) {
        vector<long long> col(n);
        for (int i = 0; i < n; i++) col[i] = a[i][j];
        sort(col.begin(), col.end(), greater<long long>());
        for (int i = 0; i < n; i++) a[i][j] = col[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << ' ';
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}   