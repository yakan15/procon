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
    ll n;cin>>n;
    vector<ll> a(n), b(n);
    vector<pair<ll,ll>> imos;
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,n) {
        imos.emplace_back(a[i], 1);
        imos.emplace_back(b[i]+1, -1);
    }
    ll res = 0, now = 0;
    sort(begin(imos), end(imos));
    for(auto x:imos) {
        now += x.second;
        chmax(res, now);
    }
    cout << res << endl;
    return 0;
}
