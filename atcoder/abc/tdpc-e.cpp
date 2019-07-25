#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

vector<vector<vector<ll> > > dp(2, vector<vector<ll> >(10002, vector<ll>(102,0))); 
int main(void) {
    int d;
    string n;
    cin>>d>>n;
    int n_len = n.size();
    int sum=0;
    // dp[1][0][0]=0;
    for(int i=1;i<=n_len;i++){
        int dig = n[i-1]-'0';
        DEBUG{cout << "dig : " << dig << endl;}
        sum +=dig;
        sum%=d;
        dp[1][i][sum]=1;
        rep(j,d){
            rep(k,10){
                dp[0][i][j]+=dp[0][i-1][(j-k+10*d)%d];
                dp[0][i][j]%=MOD;
            }
            if(dig==0){
                for(int k=0;k<10;k++){
                    dp[0][i][j]+=dp[1][i-1][(j-k-1+11*d)%d];
                    dp[0][i][j]%=MOD;
                }
            }
            else{
                rep(k,dig){
                    dp[0][i][j]+=dp[1][i-1][(j-k+10*d)%d];
                    dp[0][i][j]%=MOD;
                }
            }
            DEBUG{cout << dp[0][i][j]<<endl;}
        }
    }
    DEBUG{cout << dp[0][n_len][0] << endl;}
    cout << dp[0][n_len][0]+dp[1][n_len][0] << endl;
    return 0;
}
