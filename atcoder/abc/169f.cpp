#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 998244353;
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
    ll n,s;cin>>n>>s;
    vector<ll> a(n);
    rep(i,n) {
        cin>>a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(s+1,0));
    dp[0][0] = 1;
    rep(i,n) {
        
        rep(j,s+1) {
            // cout << i << " " << j << endl;
            if (j >= a[i]) {
                dp[i+1][j] += dp[i][j-a[i]];
            }
            dp[i+1][j] += dp[i][j] * 2;
            dp[i+1][j] %= MOD;
        }
    }
    // rep(i,n+1) {
    //     rep(j,s+1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][s] << endl;
    return 0;
}
