#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int left, right;
};
vector<Node> tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    tree.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (tree.empty()) {
            tree.push_back({x, -1, -1});
            continue;
        }

        int cur = 0;
        int depth = 0;
        while (true) {
            if (depth >= 100) break;

            if (x <= tree[cur].val) {            
                if (tree[cur].left == -1) {
                    tree.push_back({x, -1, -1});
                    tree[cur].left = tree.size() - 1;
                    break;
                }
                cur = tree[cur].left;
            } else {
                if (tree[cur].right == -1) {
                    tree.push_back({x, -1, -1});
                    tree[cur].right = tree.size() - 1;
                    break;
                }
                cur = tree[cur].right;
            }
            depth++;
        }
    }

    while (m--) {
        string p;
        cin >> p;

        int cur = 0;
        bool ok = true;
        for (char c : p) {
            cur = (c == 'L') ? tree[cur].left : tree[cur].right;
            if (cur == -1) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}