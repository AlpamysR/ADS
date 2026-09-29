#include <bits/stdc++.h>

using namespace std;
#define ll long long
int binary(vector<int>& a, int x){
    int left = 0;
    int right = a.size()-1;
    int ans = a.size();
    while(left<=right){
        int mid = left+(right-left)/2;
        if(a[mid]>=x){
            ans = mid;
            right = mid-1;
        }
        else left = mid +1;
    }
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n+1, 0);
    for(int i = 0; i<n; ++i){
        int x;
        cin>>x;
        a[i+1]= a[i]+x;
    }
    ostringstream out;
    while(m--){
        int x;
        cin>>x;
        out<<binary(a, x)<<"\n";
    }
    cout<<out.str();
    return 0;
}