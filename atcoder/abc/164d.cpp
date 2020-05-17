#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
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
    string s;cin>>s;
    ll n = s.size();
    vector<vector<ll>> dp(2, vector<ll>(2019,0));
    ll res = 0;
    rep(i,n) {
        ll pls = s[i] - '0';
        rep(j,2019) {
            dp[(i+1)%2][(j*10+pls) % 2019] = dp[i%2][j];
        }
        dp[(i+1)%2][pls]++;
        res += dp[(i+1)%2][0];
    }
    cout << res << endl;
    return 0;
}
