#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int count_one(ll x){
    int res = 0;
    rep(i,18){
        if((x>>i&1)){res++;}
    }
    return res;
}

int main(void) {
    ll n;cin>>n;
    vector<ll> x(n),c(n),v(n);
    vector<pair<ll,ll> > vc(n,pair<ll,ll>(0,0))
    rep(i,n){cin>>x.at(i);}
    rep(i,n){cin>>vc.at(i).second;}
    rep(i,n){cin>>vc.at(i).first;}
    vector<vector<ll> > resmat(n,vector<ll>(n,0));
    for(ll i=1;i<(1LL<<18);i++){
    
    }
    return 0;
}
