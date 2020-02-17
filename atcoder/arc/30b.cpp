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
    ll n,xx;cin>>n>>xx;
    xx--;
    vector<ll> juel(n);
    rep(i,n) cin>>juel[i];
    juel[xx] = 0;
    vector<vector<int>> nbs(n,vector<int>());
    rep(i,n-1) {
        int a,b;cin>>a>>b;
        a--;b--;
        nbs[a].push_back(b);
        nbs[b].push_back(a);
    }
    // vector<ll> memo(n, -1);
    function<ll(int, int)> solve = [&](int now, int par) {
        ll res = 0;
        for(auto x: nbs[now]) {
            if(x==par)continue;
            res += solve(x, now); 
        }
        if ((juel[now] != 0 || res != 0) && now != xx) res += 2;
        // return memo[now] = res;
        return res;
    };
    cout << solve(xx, -1) << endl;
    return 0;
}
