#include <bits/stdc++.h>
using namespace std;
int a[100][100], d[100], p[100];

int main() {
    int n, x = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int k = 0; k < n; k++) {
        x = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] < 100000 && d[j] > d[i] + a[i][j])
                    d[j] = d[i] + a[i][j], p[j] = i, x = j;
    }
    if (x < 0) return cout << "NO", 0;
    for (int k = 0; k <= n; k++) x = p[x];
    vector<int> c{x};
    for (int v = p[x]; v != x; v = p[v]) c.push_back(v);
    c.push_back(x);
    reverse(c.begin(), c.end());
    cout << "YES\n" << c.size() << "\n";
    for (int v : c) cout << v + 1 << " ";
}