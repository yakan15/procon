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
    ll n,k;cin>>n>>k;
    vector<ll> a(n);rep(i,n){cin>>a[i];}
    for(int i=n;i>0;i--){
        ll tmp = a[i-1];
        ll cnt=0;
        while(tmp>0){
            tmp /=2;
            cnt++;
        }
        a[i-1] = cnt;
    }
    DEBUG{
        rep(i,n){printf("%lld ",a.at(i));}
        printf("\n");
    }
    chmin(k, 70*n);
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(k+10,vector<ll>(2,0)));
    dp[0][0][0]=1;
    rep(i,n){
        // j 回数, ii iで消費する回数
        rep(j,k+1){
            for(int ii=0;j-ii>=0&&ii<a[i];ii++){
                dp[i+1][j][0] += dp[i][j-ii][0];
                dp[i+1][j][0] %= MOD;
                dp[i+1][j][1] += dp[i][j-ii][1];
                dp[i+1][j][1] %= MOD;
            }
            if(j>=a[i]){
                dp[i+1][j][1] += dp[i][j-a[i]][1];
                dp[i+1][j][1] += dp[i][j-a[i]][0];
                dp[i+1][j][1] %= MOD;
            }
        }
    }
    ll res = dp[n][k][0];
    rep(i,k+1){
        res += dp[n][i][1];
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
