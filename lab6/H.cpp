#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<char> a(n);
    for (auto &c : a) cin >> c;

    char k;
    cin >> k;

    auto it = upper_bound(a.begin(), a.end(), k);
    if (it == a.end()) it = a.begin();

    cout << *it << "\n";
    return 0;
}