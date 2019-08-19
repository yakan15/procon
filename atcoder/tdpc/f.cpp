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
    ll n,k;
    cin>>n>>k;
    ll dp[n+1][2]={};
    dp[0][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])%MOD;
        if(i>=k){
            dp[i][1]=(dp[i][1]-dp[i-k][0]+MOD)%MOD;
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}
