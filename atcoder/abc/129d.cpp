
#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll H,W;
int main(void) {
    cin >> H >> W;
    // char grid[2000][2000]={};
    vector<vector<vector<int> > > dp(4, vector<vector<int>>(H, vector<int>(W,0)));
    rep(i,H)rep(j,W){
        char tmp;
        cin >> tmp;
        if(tmp=='#'){
            rep(k,4)dp[k][i][j]=-1;
        }
    }
    // DEBUG{printf("test\n");}
    rep(i,H)rep(j,W){
        if(j>0&&dp[0][i][j]!=-1){
            if(dp[0][i][j-1]==-1)dp[0][i][j]=0;
            else dp[0][i][j]=dp[0][i][j-1]+1;
        }
        if(i>0&&dp[0][i][j]!=-1){
            if(dp[3][i-1][j]==-1)dp[3][i][j]=0;
            else dp[3][i][j]=dp[3][i-1][j]+1;
        }
        // if(i<H-1&&dp[0][H-i][j]!=-1){
        //     if(dp[1][H-i][j]==-1)dp[1][H-i-1][j]=1;
        //     else dp[1][H-i-1][j]=dp[1][H-i][j]+1;
        // }
        // if(j<W-1&&dp[0][i][W-j]!=-1){
        //     if(dp[2][i][W-j]!=-1)dp[2][i][W-j-1]=dp[2][i][W-j]+1;
        // }
    }
    for(int i=H-1;i>=0;i--)rep(j,W){
        if(i<H-1&&dp[0][i][j]!=-1&&dp[1][i+1][j]!=-1)dp[1][i][j]=dp[1][i+1][j]+1;
    }
    rep(i,H)for(int j=W-1;j>=0;j--){
        if(j<W-1&&dp[0][i][j]!=-1&&dp[2][i][j+1]!=-1)dp[2][i][j]=dp[2][i][j+1]+1;
    }
    DEBUG{
        printf("%d %d %d %d\n",dp[0][1][1], dp[1][1][1], dp[2][1][1], dp[3][1][1]);
    }
    ll res=0;
    rep(i,H)rep(j,W){
        ll s=0;
        rep(k,4){
            s+=dp[k][i][j];
        }
        s++;
        if(s>res)res=s;
    }
    cout << res << endl;
    return 0;
}
