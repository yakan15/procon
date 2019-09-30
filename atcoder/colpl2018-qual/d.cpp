#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,n){cin>>a[i];}
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    vector<ll> nxt(n);
    rep(i,n){
        auto it = upper_bound(begin(a), end(a), a[i]+k);
        it--;
        nxt[i] = it-a.begin();
    }
    rep(i,n){
        rep(j,k){
            if(nxt[i]!=i)chmax(dp[nxt[i]][j+1], dp[i][j]+a[i]);
            if(nxt[i]<n-1) chmax(dp[nxt[i]+1][j+1], dp[i][j]+a[i]);
        }
    }
    rep(i,k){
        rep(j,n){
            printf("%lld ",dp[j][i]);
        }
        printf("\n");
    }
    rep(i,k){
        ll res = 0;
        rep(j,n){
            chmax(res, dp[j][i]); 
        }
        cout << res << endl;
    }
    return 0;
}
