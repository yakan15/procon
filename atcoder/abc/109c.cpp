#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
ll n,x;
vector<ll> y;

ll gcd(ll n, ll m){
    if(m<n)return gcd(m,n);
    ll r;
    while(r=n%m){
        n=m;
        m=r;
    }
    return m;
}

int main(void) {
    cin >> n >> x;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    y.push_back(x);
    sort(y.begin(),y.end());
    ll res=y[1]-y[0];
    for(int i=2;i<n+1;i++){
        res = gcd(res,y[i]-y[i-1]);
    }
    cout << res << endl;
    return 0;
}
