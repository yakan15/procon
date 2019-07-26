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
    int n,a,b;
    cin>>n>>a>>b;
    ll v[n];
    rep(i,n)cin>>v[i];
    ll dp[n+1][51]={};
    ll dp2[n+1][51]={};
    dp2[0][0]=1;
    rep(i,n){
        rep(j,51){
            dp[i+1][j]=dp[i][j];
            dp2[i+1][j]=dp2[i][j];
        }
        for(int j=1;j<=50;j++){
            if (dp[i][j-1]+v[i]>dp[i+1][j]){
                dp[i+1][j]=dp[i][j-1]+v[i];
                dp2[i+1][j]=dp2[i][j-1];
            }
            else if(dp[i][j-1]+v[i]==dp[i+1][j]){dp2[i+1][j]+=dp2[i][j-1];}
        }
    }
    double res=0;
    ll cnt=0;
    for(int i=a;i<=b;i++){
        double tmp = double(dp[n][i])/i;
        
        if(fabs(res - tmp) <= DBL_EPSILON * fmax(1, fmax(fabs(a), fabs(b)))){
            cnt += dp2[n][i];
        }else if(res<tmp){
            res = tmp;
            cnt = dp2[n][i]; 
        } 
    }
    printf("%lf\n",res);
    cout << cnt << endl;
    return 0;
}
