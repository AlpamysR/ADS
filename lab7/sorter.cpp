#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n, vector<int>(m));
    vector<long long> sum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
            sum[i] += rows[i][j];
        }
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        if (sum[x] != sum[y]) return sum[x] > sum[y]; // larger sum first
        return rows[x] < rows[y];                     // lexicographic order
    });

    string out;
    for (int id : idx) {
        for (int j = 0; j < m; j++) {
            if (j) out += ' ';
            out += to_string(rows[id][j]);
        }
        out += '\n';
    }
    cout << out;
    return 0;
}