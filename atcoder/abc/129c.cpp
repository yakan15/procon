#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ll mod = 1000000007;
int main(void) {
    cin >> n >> m; 
    ll dp[100005]={};
    rep(i,m){
        int tmp;
        cin >> tmp;
        dp[tmp]=-1;
    }
    dp[0]=1;
    rep(i,n){
        if(dp[i]!=-1){
            if(dp[i+2]!=-1){
                dp[i+2]+=dp[i];
                dp[i+2]%=mod;
            }
            if(dp[i+1]!=-1){
                dp[i+1]+=dp[i];
                dp[i+1]%=mod;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
