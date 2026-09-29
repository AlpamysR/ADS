#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll binary(vector<ll>& a, ll x){
    ll left = 0;
    ll right = a.size()-1;
    ll ans = a.size();
    while(left<=right){
        ll mid = left + (right - left)/2;
        if(a[mid]>x){
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> pre(n+1, 0);
    for(int i = 0;i<n;++i){
        pre[i+1]=pre[i]+a[i];
    }
    ll r;
    cin>>r;
    ostringstream out;
    while(r--){
        ll x;
        cin>>x;
        ll cnt = binary(a, x);
        out<<cnt<<" "<<pre[cnt]<<"\n";
    }
    cout<<out.str();
    return 0;
}