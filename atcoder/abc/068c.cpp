#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,ll> mpa,mpb;
    rep(i,m){
        ll ta,tb;
        cin>>ta>>tb;
        if(ta==1)mpa[tb]=1;
        if(tb==n)mpb[ta]=1;
    }
    bool flg=false;
    for(auto x:mpa){
        if(mpb[x.first]==1)flg=true;
    }
    if(flg)cout<<"POSSIBLE"<<endl;
    else cout << "IMPOSSIBLE"<<endl;
    return 0;
}
