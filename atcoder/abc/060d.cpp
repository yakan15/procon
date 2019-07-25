#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    ll n,w;
    cin>>n>>w;
    vector<vector<vector<ll> > > dp(n+1, vector<vector<ll> >(n+1, vector<ll>(n*3+1,0)));
    ll weight[n],value[n];
    rep(i,n)cin>>weight[i]>>value[i];
    ll base=weight[0];
    rep(i,n)weight[i]-=base;
    for(int i=1;i<=n;i++)for(int j=0;j<=i;j++)for(int k=0;k<=n*3;k++){
        if(j==0)continue;
        dp[i][j][k]=dp[i-1][j][k];
        if(k>=weight[i-1]){
            dp[i][j][k]=max(dp[i-1][j-1][k-weight[i-1]]+value[i-1],dp[i-1][j][k]);
        }
    }
    DEBUG{cout << "1 1 0 : "<<dp[1][1][0] << endl; }
    ll res=0;
    rep(i,n+1)rep(j,n*3+1){
        if(i*base+j>w)continue;
        DEBUG{
            printf("i : %d, j : %d dp : %lld\n", i,j,dp[n][i][j]);
        }
        res=max(res,dp[n][i][j]);
    }
    cout << res << endl;
    return 0;
}
