#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> left(n+1, 0), right(n+1, 0);
    for(int i =0; i<n; ++i){
        int x, y, z;
        cin>>x>>y>>z;
        if(z==0) left[x] = y;
        else right[x]=y;
    }
    int best = 0;
    queue<int> st;
    st.push(1);
    while(!st.empty()){
        int sz = st.size();
        best = max(best, sz);
        for(int i = 0; i<sz; ++i){
            int cur = st.front();
            st.pop();
            if(left[cur]) st.push(left[cur]);
            if(right[cur]) st.push(right[cur]);
        }
    }
    cout<<best;
    return 0;
}