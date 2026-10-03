#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> val(n), lft(n, -1), rgt(n, -1);
    vector<long long> levelSum;

    for (int i = 0; i < n; i++) {
        cin >> val[i];
        if (i == 0) {
            levelSum.push_back(val[0]);
            continue;
        }
        int cur = 0, depth = 0;
        while (true) {
            depth++;
            if (val[i] < val[cur]) {
                if (lft[cur] == -1) { lft[cur] = i; break; }
                cur = lft[cur];
            } else {
                if (rgt[cur] == -1) { rgt[cur] = i; break; }
                cur = rgt[cur];
            }
        }
        if ((int)levelSum.size() <= depth) levelSum.push_back(0);
        levelSum[depth] += val[i];
    }

    cout << levelSum.size() << "\n";
    for (size_t i = 0; i < levelSum.size(); i++) {
        if (i) cout << " ";
        cout << levelSum[i];
    }
    cout << "\n";
    return 0;
}