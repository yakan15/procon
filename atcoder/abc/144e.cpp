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
    vector<ll> a(n),f(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>f[i];
    sort(begin(a),end(a));
    sort(begin(f),end(f));
    ll from = 0,to=1e+12;
    function<bool(ll)> check = [&](ll x) {
        ll cnt = 0;
        rep(i,n) {
            cnt += max(0LL,a[i]-x/f[n-1-i]);
        }
        return cnt <= k;
    };
    while(true) {
        ll mid = (from + to) / 2;
        if (check(mid)) {
            to = mid;
        }
        else {
            from = mid;
        }
        if (to-from<=1) {
            if(check(from)) {
                cout << from << endl; 
            }else {
                cout << to << endl;
            }
            return 0;
        }
    }
    return 0;
}
