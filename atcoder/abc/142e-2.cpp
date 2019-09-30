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
    ll n,m;cin>>n>>m;
    ll dp[m+1][(1<<n)+2];
    ll lim = 1LL<<45;
    ll bit[m];
    ll a[m];
    rep(i,(1<<n)+2){
        rep(j,m+1){
            dp[j][i]=lim;
        }
    }
    rep(i,m){
        ll b;cin>>a[i]>>b;
        ll bitt = 0;
        rep(i,b){
            ll tmp;cin>>tmp;
            tmp--;
            bitt += 1<<tmp;
        }
        bit[i]=bitt;
    }
    DEBUG{
        cout << "tt " << endl;
    }
    dp[0][0]=0;
    rep(i,m){
        rep(j,1<<n){
            DEBUG{
                cout << bit[i] << endl;
            }
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][j|bit[i]],min(dp[i][j]+a[i],dp[i][j|bit[i]]));
        }
    }
    ll res = dp[m][(1<<n)-1];
    cout << (res == lim ? -1 : res) << endl;
    return 0;
}
