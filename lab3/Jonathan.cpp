#include <bits/stdc++.h>

using namespace std;
#define ll long long

// number of elements <= x  (first index where a[i] > x)
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
        else left = mid+1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0;i<n;++i){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        a[i] = max(x2, y2);      
    sort(a.begin(), a.end());

    ll left = 1;
    ll right = a[n-1];           
    ll ans = right;
    while(left<=right){
        ll mid = left+(right-left)/2;
        if(upperB(a, mid)>=k){   
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout<<ans;
    return 0;
}