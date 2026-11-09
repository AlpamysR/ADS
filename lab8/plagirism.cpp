#include <bits/stdc++.h>
using namespace std;

vector<int> Z(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

int main() {
    string a, b, t;
    cin >> a >> b >> t;
    int m = t.size(), n = min(a.size(), b.size()), r = 0;
    vector<int> x = Z(t + "#" + a), y = Z(t + "#" + b);
    for (int i = 0; i < n; i++)
        r += x[m + 1 + i] >= m && y[m + 1 + i] >= m;
    cout << r;
}