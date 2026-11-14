#include <bits/stdc++.h>
using namespace std;

int p[51];

int f(int x) {
    return p[x] == x ? x : p[x] = f(p[x]);
}

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> e;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (i < j) e.push_back({x, i, j});
        }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) p[i] = i;
    int ans = 0;
    for (auto &t : e) {
        int a = f(t[1]), b = f(t[2]);
        if (a != b) {
            p[a] = b;
            ans += t[0];
        }
    }
    cout << ans;
}