#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
// const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    ll n,m;
    cin >> n >> m;
    ll s[n],t[m];
    ll dp[n+1][m+1]={},sum[n+1][m+1]={};
    rep(i,n){
        cin>>s[i];
    }
    rep(i,m){
        cin>>t[i];
    }
    rep(i,n)rep(j,m){
        if(s[i]==t[j]){
            dp[i+1][j+1]=(sum[i][j]+1+MOD)%MOD;
        }
        sum[i+1][j+1]=(sum[i][j+1]+sum[i+1][j]-sum[i][j]+dp[i+1][j+1]+MOD)%MOD;
    }
    cout << (sum[n][m]+MOD+1)%MOD << endl;
    return 0;
}
