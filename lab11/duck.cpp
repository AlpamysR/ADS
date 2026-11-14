#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long s = 0, mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s += x;
        mn = min(mn, x);
    }
    cout << s + (n - 2) * mn;
}