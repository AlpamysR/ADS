#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> val(n), lft(n, -1), rgt(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> val[i];
        if (i == 0) continue;
        int cur = 0;
        while (true) {
            if (val[i] < val[cur]) {
                if (lft[cur] == -1) { lft[cur] = i; break; }
                cur = lft[cur];
            } else {
                if (rgt[cur] == -1) { rgt[cur] = i; break; }
                cur = rgt[cur];
            }
        }
    }

    int leaves = 0;
    for (int i = 0; i < n; i++)
        if (lft[i] == -1 && rgt[i] == -1) leaves++;

    cout << leaves << endl;
    return 0;
}