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
    int n;
    double t;
    cin >> n >> t;
    vector<vector<int>> dp(3003, vector<int>(3003,0));
    vector<pair<int,int>> ab(n,pair<int,int>(0,0));
    rep(i,n) cin>>ab[i].first>>ab[i].second;
    sort(begin(ab), end(ab));
    rep(i,n) {
        rep(j,t+2) {
            dp[i+1][j] = dp[i][j];
        }
        for(int j=0;j<t;j++) {
            if (j+ab[i].first<=t) {
                chmax(dp[i+1][j+ab[i].first], dp[i][j]+ab[i].second);
            } else {
                chmax(dp[i+1][t+1], dp[i][j]+ab[i].second);
            }
        }
    }
    int res = 0;
    rep(i,t+2) {
        chmax(res, dp[n][i]);
    }
    cout << res << endl;
    return 0;
}
