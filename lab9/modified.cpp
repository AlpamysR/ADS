#include <bits/stdc++.h>
using namespace std;

static void clean(string &s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' ')) s.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string p, line;
    getline(cin, p);
    clean(p);
    getline(cin, line);
    int n = stoi(line);
    string pl = p;
    for (auto &c : pl) c = tolower((unsigned char)c);

    vector<string> a(n);
    vector<int> best(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, a[i]);
        clean(a[i]);
        string s = a[i];
        for (auto &c : s) c = tolower((unsigned char)c);
        s += '#';
        s += pl;
        int len = s.size();
        vector<int> pi(len, 0);
        for (int j = 1; j < len; j++) {
            int k = pi[j - 1];
            while (k > 0 && s[j] != s[k]) k = pi[k - 1];
            if (s[j] == s[k]) k++;
            pi[j] = k;
        }
        best[i] = pi[len - 1];
        mx = max(mx, best[i]);
    }

    if (mx == 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
        if (best[i] == mx) res.push_back(i);

    cout << res.size() << "\n";
    for (int i : res) cout << a[i] << "\n";
    return 0;
}