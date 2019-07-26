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
    int n,ma,mb;
    cin>>n>>ma>>mb;
    int a[n],b[n],c[n];
    const int lim = 1000000;
    vector<vector<vector<int> > > dp(41,vector<vector<int> >(401, vector<int>(401,lim)));
    rep(i,41)dp[i][0][0]=0;
    rep(i,n)cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++){
        rep(j,401){
            rep(k,401){
                dp[i][j][k]=dp[i-1][j][k];
            }
        }
        for(int j=0;j+a[i-1]<=400;j++){
            for(int k=0;k+b[i-1]<=400;k++){
                dp[i][j+a[i-1]][k+b[i-1]]=min(dp[i][j+a[i-1]][k+b[i-1]],dp[i-1][j][k]+c[i-1]);
            }
        }
    }
    int res=lim;
    for(int i=1;ma*i<=400&&mb*i<=400;i++){
        res=min(res,dp[n][ma*i][mb*i]);
    }

    cout << (res==lim ? -1 : res) << endl;
    return 0;
}
