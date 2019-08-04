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
    ll a[n];
    rep(i,n)cin>>a[i];
    ll cumsum[n+1]={};
    rep(i,n)cumsum[i+1]=cumsum[i]+a[i];
    ll res=1LL<<60;
    rep(i,n-1)res=min(res,abs(cumsum[n]-cumsum[i+1]*2));
    cout << res << endl;
    return 0;
}
