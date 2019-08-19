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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    rep(i,n){cin>>a[i];}
    ll sum[n+1], possum[n+1];
    sum[0]=0;
    possum[0]=0;
    rep(i,n){
        sum[i+1]=sum[i]+a[i];
        possum[i+1]=possum[i]+max(a[i],0LL);
    }
    ll res = 0;
    for(int i=0;i<=n-k;i++){
        ll psum = possum[i]+possum[n]-possum[i+k];
        ll lastsum = sum[i+k] - sum[i];
        DEBUG{cout << "sum : " << psum+max(0LL,lastsum) << endl;}
        res = max(res, psum+max(0LL,lastsum));
    }
    cout << res << endl;
    return 0;
}
