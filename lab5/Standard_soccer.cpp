#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    long long total = 0;
    while (x-- > 0 && !pq.empty()) {
        long long k = pq.top(); pq.pop();
        total += k;
        if (k - 1 > 0) pq.push(k - 1);
    }

    cout << total << "\n";
    return 0;
}