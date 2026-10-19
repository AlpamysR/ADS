#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, string> rev;
    map<string, string> fin;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        string orig = a;
        auto it = rev.find(a);
        if (it != rev.end()) {
            orig = it->second;
            rev.erase(it);
        }
        rev[b] = orig;
        fin[orig] = b;
    }

    cout << fin.size() << "\n";
    for (auto &p : fin)
        cout << p.first << " " << p.second << "\n";
    return 0;
}   