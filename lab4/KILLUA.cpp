#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> val, lft, rgt;
    map<int, int> pos; // value -> node index

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if (pos.count(v)) continue; // duplicates are not inserted

        int id = val.size();
        val.push_back(v);
        lft.push_back(-1);
        rgt.push_back(-1);

        if (id > 0) {
            auto it = pos.lower_bound(v);
            int p = -1;
            if (it != pos.end()) p = it->second;                       // successor
            if (it != pos.begin()) p = max(p, prev(it)->second);       // predecessor
            // the parent is whichever neighbour was inserted later
            if (v < val[p]) lft[p] = id;
            else rgt[p] = id;
        }
        pos[v] = id;
    }

    int m = val.size();
    vector<int> h(m, 0);
    int best = 0;

    // parents always have smaller indices than their children,
    // so going in reverse order handles children first
    for (int i = m - 1; i >= 0; i--) {
        int hl = lft[i] == -1 ? 0 : h[lft[i]];
        int hr = rgt[i] == -1 ? 0 : h[rgt[i]];
        h[i] = 1 + max(hl, hr);
        best = max(best, hl + hr + 1);
    }

    cout << best << endl;
    return 0;
}