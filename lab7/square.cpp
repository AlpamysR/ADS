#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    vector<long long> res(n);
    int l = 0, r = n - 1;
    for (int k = n - 1; k >= 0; k--) {
        if (llabs(a[l]) > llabs(a[r])) {
            res[k] = a[l] * a[l];
            l++;
        } else {
            res[k] = a[r] * a[r];
            r--;
        }
    }

    string out;
    for (int i = 0; i < n; i++) {
        if (i) out += ' ';
        out += to_string(res[i]);
    }
    out += '\n';
    cout << out;
    return 0;
}