#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long U;

int main() {
    int n;
    while (cin >> n && n) {
        vector<string> p(n);
        for (auto& s : p) cin >> s;
        string t;
        cin >> t;
        int L = t.size(), m = 0;
        vector<U> h(L + 1), w(L + 1);
        w[0] = 1;
        for (int i = 0; i < L; i++) {
            h[i + 1] = h[i] * 131 + t[i];
            w[i + 1] = w[i] * 131;
        }
        vector<int> c(n);
        for (int k = 0; k < n; k++) {
            U x = 0;
            for (char ch : p[k]) x = x * 131 + ch;
            int l = p[k].size();
            for (int i = 0; i + l <= L; i++)
                if (h[i + l] - h[i] * w[l] == x) c[k]++;
            m = max(m, c[k]);
        }
        for (int k = 0; k < n; k++)
            if (c[k] == m) cout << p[k] << "\n";
    }
}