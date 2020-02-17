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
    vector<ll> a(n);rep(i,n) cin>>a[i];
    vector<ll> cumsum(n+1,0);
    rep(i,n) cumsum[i+1] = cumsum[i] + a[i];
    ll res = 1e+15;
    repr(i,2,n-1) {
        // max,min
        vector<pair<ll,ll>> pl,pr;
        auto it = upper_bound(begin(cumsum), end(cumsum), cumsum[i]/2);
        int cur = int(it-cumsum.begin());
        if(cur != i) {
            pl.emplace_back(cumsum[cur],cumsum[i]-cumsum[cur]);
        }
        cur--;
        if (cur != 0) {
            pl.emplace_back(cumsum[i]-cumsum[cur],cumsum[cur]);
        }
        it = upper_bound(begin(cumsum), end(cumsum),
         cumsum[i] + (cumsum[n]-cumsum[i])/2);
        cur = int(it-cumsum.begin());
        if(cur != n) {
            pr.emplace_back(cumsum[cur]-cumsum[i],cumsum[n]-cumsum[cur]);
        }
        cur--;
        if (cur != i) {
            pr.emplace_back(cumsum[n]-cumsum[cur],cumsum[cur]-cumsum[i]);
        }
        for(auto x:pr) {
            for(auto y:pl) {
                chmin(res,max(x.first,y.first)-min(x.second,y.second));
            }
        }
    }
    cout << res << endl;
    return 0;
}
