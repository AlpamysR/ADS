#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll lowerB(vector<ll>& a, ll x){
    ll left = 0;
    ll right = a.size()-1;
    ll ans = a.size();
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(a[mid]>=x){
            ans = mid;
            right = mid-1;
        }
        else left=mid+1;
    }
    return ans;     
}  
ll upperB(vector<ll>& a, ll x){
    ll left = 0;
    ll right = a.size()-1;
    ll ans = a.size();
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(a[mid]>x){
            ans = mid;
            right = mid-1;
        }
        else left=mid+1;
    }
    return ans;     
}  
ll diff(vector<ll>& a, ll l, ll r){
    if(l>r) return 0;
    return upperB(a, r)-lowerB(a,l);
}
int main(){
    int n, r;
    cin>>n>>r;
    vector<ll> a(n);
    for(int i = 0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    ostringstream out;
    while(r--){
        ll l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        ll ans = diff(a, l1, r1) + diff(a, l2, r2) - diff(a, max(l1,l2), min(r1,r2));
        out<<ans<<"\n";
    }
    cout<<out.str();
    return 0;
}