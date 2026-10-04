#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    vector<int> L(n, -1), R(n, -1);
    for(int i = 0; i<n; ++i) cin>>a[i];

    int x;
    cin>>x;
    for(int i = 1; i<n; ++i){
        int cur = 0;
        while(true){
            if(a[i]<a[cur]){
                if(L[cur]==-1){
                    L[cur]=i;
                    break;
                }
                cur = L[cur];
            }
            else{
                if(R[cur]==-1){
                    R[cur]=i;
                    break;
                }
                cur=R[cur];
            }
        }
    }
    int start = 0;
    for(int i = 0; i<n; ++i){
        if(a[i]==x){
            start = i;
            break;
        }
    }

    vector<int> st;
    st.push_back(start);
    bool first = true;
    while(!st.empty()){
        int b = st.back();
        st.pop_back();
        if(!first) cout<<" ";
        cout<<a[b];
        first = false;
        if(R[b]!=-1) st.push_back(R[b]);
        if(L[b]!=-1) st.push_back(L[b]);
    }
    return 0;
}