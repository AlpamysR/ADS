#include <bits/stdc++.h>
using namespace std;
typedef long long L;

int main() {
    int n;
    cin >> n;
    vector<L> x(n), y(n), d(n, LLONG_MAX);
    vector<bool> u(n, false);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    d[0] = 0;
    for (int k = 0; k < n; k++) {
        int v = -1;
        for (int i = 0; i < n; i++)
            if (!u[i] && (v < 0 || d[i] < d[v])) v = i;
        u[v] = true;
        for (int i = 0; i < n; i++)
            if (!u[i])
                d[i] = min(d[i], max(d[v], abs(x[v] - x[i]) + abs(y[v] - y[i])));
    }
    cout << d[n - 1];
}