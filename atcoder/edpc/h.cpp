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
    ll h,w;cin>>h>>w;
    vector<string> s(h);
    rep(i,h){cin>>s.at(i);}
    vector<vector<ll> > dp(h,vector<ll>(w,0));
    dp.at(0).at(0)=1;
    rep(i,h){
        rep(j,w){
            if(s.at(i).at(j)=='#'){continue;}
            if(j!=w-1){
                dp.at(i).at(j+1) += dp[i][j];
                dp[i][j+1] %= MOD;
            }
            if(i!=h-1){
                dp.at(i+1).at(j) += dp[i][j];
                dp[i+1][j] %= MOD;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}
