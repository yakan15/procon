#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

ll gcd(ll a,ll b){
    ll r;
    if(a>b)return gcd(b,a);
    while(r=b%a){
        b=a;
        a=r;
    }
    return a;
}

int main(void) {
    int n;
    cin>>n;
    ll res=1;
    rep(i,n){
        ll tmp;
        cin>>tmp;
        res = res / gcd(res, tmp) *tmp;
    }
    cout << res << endl;
    return 0;
}
