#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int toi(char c){
    assert(c>='0'&&c<='9');
    return c-'0';
}

int main(void) {
    string s;
    cin >> s;
    int n;
    n = s.size();
    ll dp[n+1][13]={};
    DEBUG{
        cout << toi('4') << endl;
    }
    rep(i,n){
        if(i==0){
            if(s[i]=='?'){
                rep(k,10){
                    dp[i+1][k]=1;
                }
            }else{
                dp[i+1][toi(s[i])]=1;
            }
        }
        rep(j,13){
            if(s[i]=='?'){
                rep(k,10){
                    dp[i+1][(j*10+k)%13] += dp[i][j];
                    dp[i+1][(j*10+k)%13] %= MOD;
                }
            }else{
                dp[i+1][(j*10+toi(s[i]))%13] += dp[i][j];
                dp[i+1][(j*10+toi(s[i]))%13] %= MOD;
            }
        }
    }
    DEBUG{
        rep(i,n+1){
            cout << dp[i][5] << endl;
        }
    }
    cout << dp[n][5] << endl;
    return 0;
}
