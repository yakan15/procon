#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// TA解のほぼ書き写し
ll mod(ll a, ll b){
    return (a+b)%1000000007;
}

int main(void) {
    ll H,W,K;
    cin >> H >> W >> K;
    ll dp[H+1][W]={};
    dp[0][0]=1;
    rep(i,H){
        rep(j,W){
            rep(k,(1<<(W-1))){
                bool ok = true;
                rep(l,W-2){
                    if(((k>>l)&1)&&((k>>(l+1))&1))ok=false;
                }
                if(ok){
                    if(j>=1 && ((k>>(j-1))&1)){
                        dp[i+1][j-1] = mod(dp[i][j], dp[i+1][j-1]);
                    }
                    else if(j<=W-2 && ((k>>j)&1)){
                        dp[i+1][j+1] = mod(dp[i][j], dp[i+1][j+1]);
                    }else{
                        dp[i+1][j] = mod(dp[i][j], dp[i+1][j]);
                    }
                }
            }
        }
    }
    ll res = 0;

    cout << dp[H][K-1] << endl;
    return 0;
}
