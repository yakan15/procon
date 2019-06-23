#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;

ll gcd(ll n, ll m){
    if(n<m)return gcd(m,n);
    ll r;
    while(r=n%m){
        n=m;
        m=r;
    }
    return m;
}

int main(void) {
    cin >> n;
    ll res;
    cin >> res;
    rep(i,n-1){
        ll t;
        cin >> t;
        res=gcd(res,t);
    }
    cout << res << endl;
    return 0;
}
