#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, string>> v(n);
    for (auto &p : v) {
        cin >> p.second;
        int d = stoi(p.second.substr(0, 2));
        int m = stoi(p.second.substr(3, 2));
        int y = stoi(p.second.substr(6, 4));
        p.first = y * 10000 + m * 100 + d;
    }

    sort(v.begin(), v.end());

    for (auto &p : v) cout << p.second << "\n";
    return 0;
}