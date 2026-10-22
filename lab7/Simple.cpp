#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    string line;
    getline(cin, line);

    string out;
    while (T--) {
        getline(cin, line);
        vector<string> buckets[51];
        istringstream iss(line);
        string s;
        while (iss >> s) {
            buckets[s.size()].push_back(move(s));
        }
        bool first = true;
        for (int len = 1; len <= 50; len++) {
            for (const string& t : buckets[len]) {
                if (!first) out += ' ';
                out += t;
                first = false;
            }
        }
        out += '\n';
    }
    cout << out;
    return 0;
}