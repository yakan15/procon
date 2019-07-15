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
    ll n,h;
    cin>>n>>h;
    ll a[n],b[n];
    rep(i,n)cin>>a[i]>>b[i];
    sort(a,a+n,greater<ll>());
    sort(b,b+n,greater<ll>());
    ll curb=0;
    ll cnt=0;
    while(curb<n&&b[curb]>a[0]&&h>0){
        h -= b[curb];
        curb++;
        cnt++;
    }
    if(h>0)cnt+=h/a[0]+ll(h%a[0]!=0);
    cout << cnt << endl;
    return 0;
}
