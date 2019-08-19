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
    ll n,x;
    cin>>n>>x;
    ll a[n];
    rep(i,n){cin>>a[i];}
    ll _min[n];
    rep(i,n){_min[i]=1LL<<60;}
    ll res = 1LL<<60;
    rep(i,n){
        ll sum = x*i;
        rep(j,n){
            _min[j] = min(_min[j],a[(i+j)%n]);
            sum += _min[j];
        }
        DEBUG{cout << "i : " << i << " sum : " << sum << endl;}
        res = min(sum,res);
    }
    cout << res << endl;
    return 0;
}
