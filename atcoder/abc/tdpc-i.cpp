#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    string s;
    cin>>s;
    int n=s.size();
    int dp[n][n]={};
    int dp2[n][n]={};
    for(int i=0;i<=n-3;i++){
        if (s.substr(i,3)=="iwi")dp[i][i+2]=dp2[i][i+2]=1;
    }
    for(int i=3;i<=n-1;i++){
        for(int j=0;j+i<=n-1;j++){
            bool flg = dp2[j+2][j+i-1]>0&&s.substr(j,2)=="iw"&&s[j+i]=='i' ||
            dp2[j+1][j+i-2]>0&&s[j]=='i'&&s.substr(j+i-1,2)=="wi";
            if(flg){
                dp[j][j+i]=max(dp[j+2][j+i-1],dp[j+1][j+i-2])+1;
                dp2[j][j+i]=1;    
            }
            else{
                for(int k=0;k<i;k++){
                    dp[j][j+i]=max(dp[j][j+i],dp[j][j+k]+dp[j+k+1][j+i]);
                }
            }
        }
    }
    cout << dp[0][n-1]<<endl;
    return 0;
}
