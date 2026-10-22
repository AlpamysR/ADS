#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;

    string out;
    int i = 0, j = 0;
    bool first = true;
    auto put = [&](int v) {
        if (!first) out += ' ';
        out += to_string(v);
        first = false;
    };

    while (i < n && j < m) {
        if (a[i] <= b[j]) put(a[i++]);
        else put(b[j++]);
    }
    while (i < n) put(a[i++]);
    while (j < m) put(b[j++]);

    out += '\n';
    cout << out;
    return 0;
}