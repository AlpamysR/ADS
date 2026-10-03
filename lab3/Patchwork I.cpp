#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& a, long long target){
    int left = 0;
    int right = (int)a.size() - 1;
    int ans = a.size();              // default: no element >= target

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] >= target){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ostringstream out;
    while(m--){
        long long x;
        cin >> x;
        out << binarySearch(a, x) << "\n";
    }
    cout << out.str();
}