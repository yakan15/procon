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
    vector<ll> c;
    vector<vector<ll>> st(ll(1e+5)*2+5);
    ll prev = -1;
    rep(i,n){
        ll tmp;cin>>tmp;
        if(tmp!=prev){
            c.push_back(tmp);
            prev = tmp;
        }
    }
    ll cs = c.size();
    rep(i, cs) {
        st[c[i]].push_back(i);
    }
    vector<vector<ll>> dp(cs,vector<ll>(2,0));
    dp[0][0] = 1;
    repr(i, 1, cs) {
        auto it = lower_bound(begin(st[c[i]]), end(st[c[i]]), i);
        if(it!=st[c[i]].begin()){
            it--;
            dp[i][1] += dp[*it][0] + dp[*it][1];
            dp[i][1] %= MOD;
        }
        if(i > 0) {
            dp[i][0] += dp[i-1][0];
            dp[i][0] += dp[i-1][1];
            dp[i][0] %= MOD;
        }
        DEBUG{
            printf("i: %d, 0: %lld, 1: %lld\n", i, dp[i][0], dp[i][1]);
        }
    }
    cout << (dp[cs-1][0] + dp[cs-1][1]) % MOD << endl;
    return 0;
}
