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
    ll n;cin>>n;
    vector<ll> c(n);
    rep(i,n) {
        cin>>c[i];
    }
    sort(begin(c),end(c));
    vector<ll> mp4(200101,0);
    mp4[0] = 1; 
    ll res = 0;
    rep(i,200100) {
        mp4[i+1] = mp4[i] * 4;
        mp4[i+1] %=MOD;
    }
    rep(i,n) {
        ll tmp = mp4[n-1] * (n-i-1) % MOD;
        res = (res + (tmp + 2 * mp4[n-1]) % MOD *c[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}
