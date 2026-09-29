#include <bits/stdc++.h>

using namespace std;
#define ll long long

// number of blocks needed if every block sum must be <= s
int blocksNeeded(vector<ll>& a, ll s){
    int cnt = 1;
    ll cur = 0;
    for(ll x : a){
        if(cur + x > s){
            cnt++;
            cur = x;
        } else {
            cur += x;
        }
    }
    return cnt;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll left = *max_element(a.begin(), a.end());
    ll right = accumulate(a.begin(), a.end(), 0LL);
    ll ans = right;
    while(left <= right){
        ll mid = left + (right - left) / 2;
        if(blocksNeeded(a, mid) <= k){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
    return 0;
}