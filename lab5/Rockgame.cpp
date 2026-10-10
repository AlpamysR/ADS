#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        long long y = pq.top();
        pq.pop();
        long long x = pq.top();
        pq.pop();
        if (y != x) pq.push(y - x);
    }

    cout << (pq.empty() ? 0 : pq.top()) << "\n";
    return 0;
}