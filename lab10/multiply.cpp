#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    const int N = 20001;
    vector<int> d(N + 1, -1), p(N + 1, 0);
    queue<int> q;
    d[a] = 0;
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y[2] = {x * 2, x - 1};
        for (int i = 0; i < 2; i++) {
            if (y[i] >= 1 && y[i] <= N && d[y[i]] == -1) {
                d[y[i]] = d[x] + 1;
                p[y[i]] = x;
                q.push(y[i]);
            }
        }
    }
    cout << d[b] << "\n";
    vector<int> r;
    int c = b;
    while (c != a) {
        r.push_back(c);
        c = p[c];
    }
    reverse(r.begin(), r.end());
    for (int x : r) cout << x << " ";
}