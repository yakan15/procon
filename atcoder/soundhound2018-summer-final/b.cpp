#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
const ll INF = 1LL<<50;

int main(void) {
    ll n,k;
    cin>>n>>k;
    ll b[n];
    rep(i,n){
        cin>>b[i];
    }
    ll dp[n+1][2];
    rep(i,n)dp[i][0]=dp[i][1]=-INF;
    dp[n][0]=0;
    for(int i=n-1;i>=0;i--){
        dp[i][0] = max(dp[i][0],dp[i+1][0]+b[i]);
        if(i<=n-k){
            dp[i][1] = max(dp[i][1],dp[i+k][0]);
        }
        dp[i][1] = max(dp[i][1], dp[i+1][1]);
        dp[i][0] = max(dp[i][0], dp[i+1][1] + b[i]);
    }
    DEBUG{
        
    }
    cout << max(dp[0][1], dp[0][0]) << endl;
    return 0;
}
