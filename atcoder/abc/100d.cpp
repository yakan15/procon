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
    cin >> n >> m;
    ll x[n],y[n],z[n];
    rep(i,n){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll res=0;
    ll tmp[n]={};
    rep(i,2)rep(j,2)rep(k,2){
        rep(l,n){
            tmp[l]=0;
            if(i==0)tmp[l]+=x[l];
            else tmp[l]-=x[l];
            if(j==0)tmp[l]+=y[l];
            else tmp[l]-=y[l];
            if(k==0)tmp[l]+=z[l];
            else tmp[l]-=z[l];
        }
        sort(tmp,tmp+n, greater<ll>());
        ll sum=0;
        rep(l,m)sum+=tmp[l];
        res = max(res,sum);
    }
    cout << res << endl;
    return 0;
}
