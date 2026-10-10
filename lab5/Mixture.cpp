#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long d;
        cin >> d;
        pq.push(d);
    }

    int ops = 0;
    while (!pq.empty() && pq.top() < m) {
        if (pq.size() < 2) {
            cout << -1 << "\n";
            return 0;
        }
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + 2 * b);
        ops++;
    }

    cout << ops << "\n";
    return 0;
}