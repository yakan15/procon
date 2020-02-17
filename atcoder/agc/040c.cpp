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
const ll MOD = 998244353;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    ll dp[2][4]={};
    dp[1][0]=2;
    dp[1][1]=2;
    dp[1][2]=2;
    dp[1][3]=1;
    ll num[4] = {4,2,2,1};
    rep(i,n/2-1) {
        rep(j,4) {
            rep(k,4) {
                ll add;
                if (j==0&&k==0)continue;
                if (j!=3&&k==0)add=2;
                else {add=num[k];}
                dp[i%2][k] += dp[(i+1)%2][j]*add;
                dp[i%2][k] %= MOD;
            }
        }
    }
    int cur = n/2%2;
    ll res = 0;
    rep(i,4){res += dp[cur][i];}
    cout << res << endl;
    return 0;
}
