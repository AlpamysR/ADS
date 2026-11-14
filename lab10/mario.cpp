#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    queue<pair<int,int>> q;
    int cnt = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) q.push({i, j});
            if (a[i][j] == 1) cnt++;
        }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int t = 0;
    while (!q.empty() && cnt > 0) {
        int s = q.size();
        while (s--) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && a[nx][ny] == 1) {
                    a[nx][ny] = 2;
                    cnt--;
                    q.push({nx, ny});
                }
            }
        }
        t++;
    }
    cout << (cnt == 0 ? t : -1);
}