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

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,c;cin>>n>>c;
    vector<ll> a(n), b(n);
    rep(i,n){cin>>a[i];}
    rep(i,n){cin>>b[i];}
    ll lim = 401;
    vector<vector<ll>> dp(n+1, vector<ll>(c+1, 0));
    vector<vector<ll>> sum(n+1,vector<ll>(c+1, 0));
    rep(i,n){
        rep(j,c+1){
            repr(k,a[i], b[i]+1){
                sum[i][j] += modpow(k, j, MOD);
                sum[i][j] %= MOD;
            }
        }
    }
    dp[0][0]=1;
    rep(i,n){
        rep(j,c+1){
            for(int k=0;j+k<=c;k++){
                dp[i+1][j+k] += dp[i][j]*sum[i][k];
                dp[i+1][j+k] %= MOD;
            }
        }
    }
    cout << dp[n][c] << endl;
    return 0;
}
