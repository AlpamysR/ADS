#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;

    string result;
    result.reserve(s.size());
    for (int i = 0; i < 26; i++)
        result.append(cnt[i], (char)('a' + i));

    cout << result << "\n";
    return 0;
}