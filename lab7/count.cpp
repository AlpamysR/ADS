#include <bits/stdc++.h>
using namespace std;

long long countInv(vector<int>& a, vector<int>& tmp, int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    long long cnt = countInv(a, tmp, l, mid) + countInv(a, tmp, mid, r);

    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            cnt += mid - i; 
        }
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < r) tmp[k++] = a[j++];
    for (int t = l; t < r; t++) a[t] = tmp[t];
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), tmp(n);
    for (auto &x : a) cin >> x;

    cout << countInv(a, tmp, 0, n) << "\n";
    return 0;
}