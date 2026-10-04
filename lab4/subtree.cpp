#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> val(n);
    vector<int> L(n, -1), R(n, -1);

    for (int i = 0; i < n; i++) cin >> val[i];

    long long x;
    cin >> x;

    for (int i = 1; i < n; i++) {
        int cur = 0;
        while (true) {
            if (val[i] < val[cur]) {
                if (L[cur] == -1) { L[cur] = i; break; }
                cur = L[cur];
            } else {
                if (R[cur] == -1) { R[cur] = i; break; }
                cur = R[cur];
            }
        }
    }

                                                            
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (val[i] == x) { start = i; break; }
    }


    int count = 0;
    vector<int> st;
    st.push_back(start);
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        count++;
        if (L[u] != -1) st.push_back(L[u]);
        if (R[u] != -1) st.push_back(R[u]);
    }

    cout << count << "\n";
    return 0;
}