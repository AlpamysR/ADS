#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lft(n + 1, 0), rgt(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) lft[x] = y;
        else rgt[x] = y;
    }

    int best = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int sz = q.size();
        best = max(best, sz);
        for (int i = 0; i < sz; i++) {
            int cur = q.front();
            q.pop();
            if (lft[cur]) q.push(lft[cur]);
            if (rgt[cur]) q.push(rgt[cur]);
        }
    }

    cout << best << endl;
    return 0;
}