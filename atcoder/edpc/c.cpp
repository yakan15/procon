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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    ll act[3][n];
    rep(j,n){
        rep(i,3){cin>>act[i][j];}
    }
    ll dp[3][n];
    rep(i,3){
        dp[i][0]=act[i][0];
    }
    repr(i,1,n){
        rep(j,3){
            dp[j][i]=max(dp[(j+1)%3][i-1],dp[(j+2)%3][i-1])+act[j][i];
            DEBUG{printf("j %d, i %d, dp %lld\n", j,i,dp[j][i]);}
        }
    }
    ll res = 0;
    rep(i,3){
        res = max(res, dp[i][n-1]);
    }
    cout << res << endl;
    return 0;
}
