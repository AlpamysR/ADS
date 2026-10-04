#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> res(n);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        res[i] = sum;   // sum of all keys >= a[i]
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << endl;
    return 0;
}