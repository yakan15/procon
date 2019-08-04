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
    cin>>n>>m;
    ll res=1;
    if(abs(n-m)>1)res=0;
    if(n==m)res*=2;
    rep(i,n){
        res*=i+1;
        res%=MOD;
    }
    rep(i,m){
        res*=i+1;
        res%=MOD;
    }
    cout << res << endl;
    return 0;
}
