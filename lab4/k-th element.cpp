#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &v : a) cin >> v;

    if (k > n) {
        cout << -1 << endl;
        return 0;
    }

    sort(a.begin(), a.end());
    cout << a[k - 1] << endl;
    return 0;
}