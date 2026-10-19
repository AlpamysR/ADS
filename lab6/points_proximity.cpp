#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    long long best = LLONG_MAX;
    for (int i = 0; i + 1 < n; i++)
        best = min(best, a[i + 1] - a[i]);

    bool first = true;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i + 1] - a[i] == best) {
            if (!first) cout << ' ';
            cout << a[i] << ' ' << a[i + 1];
            first = false;
        }
    }
    cout << "\n";
    return 0;
}