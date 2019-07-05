#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

ll parent[100005];
ll root(ll a){
    if(parent[a]==a)return a;
    return parent[a] = root(parent[a]);
}

void unite(ll x,ll y){
    ll rx = root(x);
    ll ry = root(y);
    parent[rx] = ry;
}


int main(void) {
    ll n,m;
    cin >> n >> m;
    ll p[n];
    vector<pair<ll, ll> > xy;
    rep(i,n)cin >> p[i];
    rep(i,m){
        ll tx,ty;
        cin >> tx >> ty;
        xy.push_back(make_pair(tx,ty));
    }
    rep(i,n+1)parent[i]=i;
    rep(i,m){
        unite(xy[i].first,xy[i].second);
    } 
    ll res=0;
    DEBUG{
        rep(i,n){
            printf("p%d : %lld\n", i+1, parent[i+1]);
        }
    }
    rep(i,n){
        if(root(i+1)==root(p[i]))res++;
    }
    cout << res << endl;
    return 0;
}
