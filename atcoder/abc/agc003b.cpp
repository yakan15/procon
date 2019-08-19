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
    ll res=0;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n-1){
        res += a[i] / 2;
        a[i] %= 2;
        ll tmp = min(a[i+1],a[i]);
        res += tmp;
        a[i+1] -= tmp;
        a[i] -= tmp;
    }
    res += a[n-1]/2;
    cout << res << endl;
    return 0;
}
