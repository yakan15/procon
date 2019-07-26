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
    int n,m;
    cin>>n>>m;
    ll x[n],y[m];
    ll xsum=0,ysum=0;
    rep(i,n){cin>>x[i];}
    ll x0=x[0],y0=y[0];
    rep(i,n){x[i]-=x0;}
    DEBUG{rep(i,n)cout<<x[i]<<" ";}
    rep(i,m){cin>>y[i];}
    rep(i,n){y[i]-=y0;}
    for(int i=n-1;i>=0;i--){
        DEBUG{cout<<(2*i-n+1)*x[i]<<endl;}
        xsum+=(2*i-n+1)*x[i];
    }
    DEBUG{cout << xsum<<endl;}
    for(int i=m-1;i>=0;i--){
        ysum+=(2*i-m+1)*y[i];
    }
    DEBUG{cout << ysum<<endl;}
    xsum%=MOD;
    ysum%=MOD;
    cout << (xsum*ysum)%MOD << endl;
    return 0;
}
