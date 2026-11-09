#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll prev = 0;
    string s;
    for (int i = 0; i < n; i++) {
        ll p;
        cin >> p;
        ll d = (p - prev) >> i;
        s += char('a' + d);
        prev = p;
    }
    cout << s << endl;
}