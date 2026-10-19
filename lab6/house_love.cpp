#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> res;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }

    for (size_t k = 0; k < res.size(); k++) {
        if (k) cout << ' ';
        cout << res[k];
    }
    cout << "\n";
    return 0;
}