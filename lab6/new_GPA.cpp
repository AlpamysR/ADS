#include <bits/stdc++.h>
using namespace std;

struct Student {
    string last, first;
    long long num, den;
    double gpa;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> scale = {
        {"A+", 400}, {"A", 375}, {"B+", 350}, {"B", 300}, {"C+", 250},
        {"C", 200}, {"D+", 150}, {"D", 100}, {"F", 0}
    };

    int n;
    cin >> n;

    vector<Student> v(n);
    for (auto &s : v) {
        int m;
        cin >> s.last >> s.first >> m;
        s.num = 0;
        s.den = 0;
        for (int i = 0; i < m; i++) {
            string g;
            long long c;
            cin >> g >> c;
            s.num += scale[g] * c;
            s.den += c;
        }
        s.gpa = (double)s.num / 100.0 / (double)s.den;
    }

    sort(v.begin(), v.end(), [](const Student &a, const Student &b) {
        __int128 l = (__int128)a.num * b.den;
        __int128 r = (__int128)b.num * a.den;
        if (l != r) return l < r;
        if (a.last != b.last) return a.last < b.last;
        return a.first < b.first;
    });

    for (auto &s : v)
        printf("%s %s %.3f\n", s.last.c_str(), s.first.c_str(), s.gpa);

    return 0;
}