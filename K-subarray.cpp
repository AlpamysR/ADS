#include <bits/stdc++.h>

using namespace std;
#define ll long long

int lowerB(vector<ll>& a, int x, long long b){
    int left = x;
    int right = a.size()-1;
    int ans = a.size();
    while(left<=right){
        int mid = left + (right-left)/2;
        if(a[mid]>=b){
            ans = mid;
            right = mid -1;
        }
        else left = mid +1;
    }
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<long long> a(n+1, 0);
    for(int i = 0;i<n;++i){
        int x;
        cin>>x;
        a[i+1] = a[i]+x;
    }

    int best = n;
    for(int i = 0;i<n; ++i){
        int j = lowerB(a, i+1,a[i]+m);
        if(j<=n) best = min(best, j-i);
    }
    cout<<best;
    return 0;
}