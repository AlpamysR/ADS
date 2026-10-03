#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll hoursNeeded(vector<ll>& a, ll k){
    ll cnt = 0;
    for(long long x:a){
        cnt+=(x+k-1)/k;
    }
    return cnt;
}
int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0;i<n;++i){
        cin>>a[i];
    }
    ll left = 1;
    ll right = *max_element(a.begin(), a.end());
    ll ans = right;
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(hoursNeeded(a, mid)<=k){
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout<<ans;
    return 0;
}