#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
// 0:a,1:t,2:g,3:c
int main(void) {
    cin >> n;
    ll dp[n+1][4][4][4]={};
    rep(i,4)rep(j,4)rep(k,4){
        if(i==0&&j==2&&k==3)continue;
        if(i==2&&j==0&&k==3)continue;
        if(i==0&&j==3&&k==2)continue;
        dp[3][i][j][k]=1;
    }
    for(int a=4;a<n+1;a++)rep(i,4)rep(j,4)rep(k,4){
        if(i==0&&j==2&&k==3)continue;
        if(i==2&&j==0&&k==3)continue;
        if(i==0&&j==3&&k==2)continue;
        rep(l,4){
            if(l==0&&i==2&&k==3)continue;
            if(l==0&&j==2&&k==3)continue;
            dp[a][i][j][k]+=dp[a-1][l][i][j];
            dp[a][i][j][k]%=1000000007;
        }
    }
    ll res=0;
    rep(i,4)rep(j,4)rep(k,4){
        res += dp[n][i][j][k];
        res %= 1000000007;
    }
    cout << res << endl;
    return 0;
}
