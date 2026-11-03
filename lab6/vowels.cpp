#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;

    string vowels = "aeiou";
    string result;
    result.reserve(s.size());

    for (char v : vowels)
        result.append(cnt[v - 'a'], v);

    for (char c = 'a'; c <= 'z'; c++) {
        if (vowels.find(c) == string::npos)
            result.append(cnt[c - 'a'], c);
    }

    cout << result << "\n";
    return 0;
}