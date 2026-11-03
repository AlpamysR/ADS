#include <bits/stdc++.h>
using namespace std;
struct Student{
    string last, first;
    long long num, den;
    double gpa;
};
bool cmp(const Student &a, const Student &b){
    long long l = a.num*b.den;
    long long r = b.num*a.den;
    if(l!=r) return l<r;
    if(a.last!=b.last) return a.last <b.last;
    return a.first <b.first;
}
void r(vector<Student> &a){
    int n = a.size();
    for(int i = 0; i<n-1; ++i){
        for(int j =0; j<n-i-1; ++j){
            if(cmp(a[j+1], a[j])) swap(a[j], a[j+1]);
        }
    }
}
int main(){
    map<string, int> points = {
        {"A+", 400}
    };
    int n;
    cin>>n;
    vector<Student> a(n);
    for(auto &x : a){
        int m;
        cin>>x.last>>x.first>>m;
        x.num= 0;
        x.den =0;
        for(int i =0;i<m; ++i){
            string s;
            long long c;
            cin>>s>>c;
            x.num += points[s] * c;
            x.den += c;
        }
        x.gpa = (double)x.num/100.0/(double)x.den;
    }
    r(a);
    for(auto &x : a) printf("%s %s %.3f\n", x.last.c_str(), x.first.c_str(), x.gpa);
    return 0;
}
