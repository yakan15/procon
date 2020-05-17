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
    ll n;cin>>n;
    vector<pair<ll,ll>> a;
    rep(i,n) {
        ll tmp;cin>>tmp;
        a.emplace_back(tmp, i);
    }
    if (n==1) {
        cout << 0 << endl;
        return 0;
    }
    if (n==2) {
        cout << a[0].first + a[1].first << endl;
        return 0;
    }
    vector<bool> chk(n, true);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    sort(all(a),greater<pair<ll,ll>>());
    rep(i,n) {
        rep(j,i+1) {
            ll place = a[i].second, value = a[i].first;
            chmax(dp[i+1][j+1], dp[i][j] + value * abs(place-j));
            chmax(dp[i+1][j], dp[i][j] + value * abs(n-1-i+j-place));
        }
    }
    ll res = 0;
    rep(i,n) {
        chmax(res, dp[n][i]);
    }
    cout << res << endl;
    return 0;
}
