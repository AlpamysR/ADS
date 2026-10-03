#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
bool ok(vector<ll>& a,ld L, int k){
    ll cnt = 0;
    for(ll x: a){
        cnt += (ll)floorl(x/L);
        if(cnt >=k){
            return true;
        }
    }
    return false;
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i<n;i++){
        cin>>a[i];
    }
    ld left = 0 ;
    ld right = *max_element(a.begin(), a.end());
    for(int i = 0; i<100;++i){
        ld mid = left+(right-left)/2;
        if(ok(a, mid, k)) left= mid;
        else right = mid;
    }
    printf("%.9f", (double)left);
    return 0;
}
