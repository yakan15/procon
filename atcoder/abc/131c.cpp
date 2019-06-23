#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a,b,c,d;

ll gcd(ll n,ll m){
    if(n<m) return gcd(m,n);
    ll tmp;
    while(tmp=n%m){
        n=m;
        m=tmp;
    }
    return m;
}

int main(void) {
    cin >> a >> b >> c >> d;
    ll x=(d*c)/gcd(c,d);
    // DEBUG{cout << x << endl;}
    ll cnt=0;
    cnt += b/c;
    cnt -= (a-1)/c;
    cnt += b/d;
    cnt -= (a-1)/d;
    cnt -= b/x;
    cnt +=(a-1)/x;
    cout << b-a+1-cnt << endl;

    return 0;
}
