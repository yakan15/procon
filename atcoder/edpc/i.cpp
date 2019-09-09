#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<double> prob(n);rep(i,n){cin>>prob[i];}
    double dp[n+1][n+1];
    rep(i,n+1){
        rep(j,n+1){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    rep(j,n/2+2){
        repr(i,1,n+1){
            if(j==n/2+1){dp[i][j]+=dp[i-1][j];}
            else{dp[i][j] += dp[i-1][j]*(1-prob.at(i-1));}
            if(j!=0){
                dp[i][j] += dp[i-1][j-1]*prob.at(i-1);
            }
        }
    }
    // double res=0;
    DEBUG{
        rep(i,n+1){
            cout << dp[n][i] << endl;
        }
    }
    // repr(i,n/2+1,n+1){
    //     res += dp[n][i]; 
    // } 
    printf("%.10f\n",dp[n][n/2+1]);
    return 0;
}
