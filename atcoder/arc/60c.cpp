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
    int n,a;
    cin>>n>>a;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(2501, 0)));
    dp[0][0][0] = 1;
    vector<ll> x(n);
    rep(i,n){cin>>x[i];}
    rep(i,n){
        rep(j,n){
            rep(k,2501){
                dp[i+1][j][k] += dp[i][j][k];
                if(k + x[i] <= 2500) {
                    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                }
            }
        }
    }
    ll res = 0;
    repr(i,1,n+1){
        res += dp[n][i][i*a]; 
    }
    cout << res << endl;
    return 0;
}
