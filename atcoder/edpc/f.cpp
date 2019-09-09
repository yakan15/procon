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
    string s,t;cin>>s>>t;
    int lens=s.size(),lent=t.size();
    int dp[lens+1][lent+1]={};
    rep(i,lens){
        rep(j,lent){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else if(dp[i+1][j]>dp[i][j+1]){
                dp[i+1][j+1]=dp[i+1][j];
            }else{
                dp[i+1][j+1]=dp[i][j+1];
            }
        }
    }
    string res = "";
    int cnt=dp[lens][lent];
    int curs=lens,curt=lent;
    while(cnt>0){
        if(dp[curs][curt]==dp[curs][curt-1]){
            curt--;
        }else if(dp[curs][curt]==dp[curs-1][curt]){
            curs--;
        }
        else if(dp[curs][curt]==1+dp[curs-1][curt-1]){
            res.insert(res.begin(),s[curs-1]);
            curs--;
            curt--;
            cnt--;
        }
    }
    cout << res << endl;
    return 0;
}
