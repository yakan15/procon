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
    ll h,w,k;cin>>h>>w>>k;
    vector<vector<ll>> dp(h+1,vector<ll>(w,0));
    dp[0][0]=1;
    rep(i,h){
        rep(j,w){
            rep(k,1<<w-1){
                ll mask = 3;
                bool flg = false;
                rep(l,w-1){
                    flg |= (k>>l&3)==3;
                }
                if(flg){
                    DEBUG{
                        printf("continue k: %d\n",k);
                    }
                    continue;
                }
                if(j<w-1&&k>>j&1){
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= MOD;
                }else if(j>0&&k>>(j-1)&1){
                    dp[i+1][j-1] += dp[i][j];
                    dp[i+1][j-1] %= MOD;
                }else{
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= MOD;
                }
            }
        }
    }
    cout << dp[h][k-1] << endl;
    return 0;
}
