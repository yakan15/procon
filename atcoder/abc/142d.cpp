#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b;cin>>a>>b;
    ll x = __gcd(a,b);
    ll aa = a/x, bb = b/x;
    set<ll> res,cand;
    ll lim = a/x*b;
    ll tmp = x;
    bool chk[1000020]={};
    DEBUG{
        printf("%lld %lld %lld\n",x,aa,bb);
    }
    res.insert(1);
    for(ll i=2;i*i<=x;i++){
        if(chk[i]){continue;}
        if(x%i==0){
            res.insert(i);
            while(tmp%i==0){
                tmp/=i;
            }
        }
        ll j = 1;
        while(i*j<1000020){
            chk[i*j]=true;
            j++;
        }
    }
    res.insert(tmp);
    cout << res.size() << endl;
    return 0;
}
