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
    ll n,k;cin>>n>>k;
    vector<int> a(n);rep(i,n){cin>>a[i];}
    sort(begin(a),end(a));
    vector<unordered_map<int,int>> dp(n+1);
    dp[0][0]=1;
    rep(i,n){
        for(auto x:dp[i]){
            dp[i+1][x.first] += dp[i][x.first];
            dp[i+1][x.first] %= MOD;
            int cur = a[i]^x.first;
            dp[i+1][cur] += dp[i][x.first];
            dp[i+1][cur] %= MOD;
        }
    } 
    cout << dp[n][k] << endl;
    return 0;
}
