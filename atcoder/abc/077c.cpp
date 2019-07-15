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
    ll n;
    cin>>n;
    vector<ll> a(n,0),b(n,0),c(n,0);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll cumsum[n+1]={};
    rep(i,n){
        cumsum[i+1]=cumsum[i]+ll(lower_bound(a.begin(),a.end(),b[i])-a.begin());
    }
    DEBUG{
        rep(i,n)cout << cumsum[i+1]<<endl;
    }
    ll res=0;
    rep(i,n){
        ll cur= ll(lower_bound(b.begin(),b.end(),c[i])-b.begin());
        DEBUG{cout << cur << endl;}
        res+=cumsum[cur];
    }
    cout << res << endl;
    return 0;
}
