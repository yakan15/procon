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
    vector<ll> l(n);
    rep(i,n) {
        cin>>l[i];
    }
    sort(begin(l), end(l));
    ll res = 0;
    repr(i, 2, n) {
        ll mx = l[i];
        repr(j, 1, i) {
            ll m2 = l[j];
            auto it = upper_bound(begin(l), end(l), mx - m2);
            res += max(0LL, ll(j) - ll(it - l.begin()));
        }
    }
    cout << res << endl;
    return 0;
}
