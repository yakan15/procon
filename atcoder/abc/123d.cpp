#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll x,y,z,k;
int main(void) {
    cin >>x>>y>>z>>k;
    vector<ll> a,b,c;
    ll tmp;
    rep(i,x){
        cin >> tmp;
        a.push_back(tmp);
    }
    rep(i,y){
        cin >> tmp;
        b.push_back(tmp);
    }
    rep(i,z){
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    sort(c.begin(),c.end(),greater<ll>());
    int cur[3]={0,0,0};
    rep(i,k-1){
        cout << a[cur[0]]+b[cur[1]]+c[cur[2]] << endl;    
        ll min_diff=1LL<<60; 
        int inc=-1;
        if(cur[0]<x-1&&a[cur[0]]-a[cur[0]+1]<min_diff){
            inc=0;
            min_diff=a[cur[0]]-a[cur[0]+1];
        }
        if(cur[1]<y-1&&b[cur[1]+1]-b[cur[1]+1]<min_diff){
            inc=1;
            min_diff=b[cur[1]]-b[cur[1]+1];
        }
        if(cur[2]<z-1&&c[cur[2]]-c[cur[2]+1]<min_diff){
            inc=2;
            min_diff=c[cur[2]]-c[cur[2]+1];
        }
        if(inc!=-1)cur[inc]++; 
    }

    return 0;
}
