#include <bits/stdc++.h>
using namespace std;

int p[100001];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        p[f(x)] = f(y);
    }
    int s, e;
    cin >> s >> e;
    cout << (f(s) == f(e) ? "YES" : "NO");
}