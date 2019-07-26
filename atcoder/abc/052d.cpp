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
    ll n,a,b;
    cin>>n>>a>>b;
    ll x[n];
    rep(i,n){cin>>x[i];}
    ll res=0;
    rep(i,n-1){
        ll walk = a*(x[i+1]-x[i]);
        res += (walk > b) ? b : walk;
    }
    cout << res << endl;
    return 0;
}
