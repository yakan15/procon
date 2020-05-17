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
    vector<vector<ll>> children(n);
    vector<ll> v(n);
    rep(i,n) {
        cin>>v[i];
        v[i]--;
    }
    rep(i,n-1) {
        ll a,b;cin>>a>>b;
        a--;b--;
        children[a].push_back(b);
        children[b].push_back(a);
    }
    ll lim = 1LL<<60; 
    vector<ll> dp(n,lim);
    vector<ll> res(n,-1);
    function<void(ll, ll)> dfs = [&] (ll num, ll par) {
        auto cur = lower_bound(all(dp), v[num]);
        ll idx = ll(cur-begin(dp)), val;
        val = dp[idx];
        dp[idx] = v[num];
        for (auto x:children[num]) {
            if (x == par) {
                continue;
            }
            dfs(x, num);
        }
        auto lis = lower_bound(all(dp), lim);
        res[num] = ll(lis - begin(dp));
        dp[idx] = val;
    };
    dfs(0, 0);
    rep(i,n) {
        cout << res[i] << endl;
    }
    return 0;
}
