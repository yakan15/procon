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
    ll n;
    cin>>n;
    vector<ll> a(n), memo(n,0);
    vector<vector<ll>> child(n);
    
    rep(i,n-1) {
        cin>>a[i];
        a[i]--;
        child[a[i]].push_back(i+1);
    }
    // function<ll(ll)> solve = [&] (ll num) {
    //     ll res = 0;
    //     if (child[num].size()==0) {
    //         return 1LL;
    //     }
    //     for(auto x:child[num]) {
    //         res += solve(x);
    //     }
    //     return memo[num] = res;
    // };
    // solve(0);
    rep(i,n) {
        cout << child[i].size() << endl;
    }
    return 0;
}
