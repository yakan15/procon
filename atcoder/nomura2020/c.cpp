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
    vector<ll> a(n+1);
    rep(i,n+1) {cin>>a[i];}
    ll sum = 0;
    ll now = 1;
    vector<ll> csum(n+2,0);
    ll budget = 0;
    rep(i,n+1) {
        budget += a[i];
    }
    rep(i,n+1) {
        sum += now;
        if (i < n) {
            if (now < a[i]) {
                cout << -1 << endl;
                return 0;
            }
            now -= a[i];
            budget -= a[i];
            now = min(now * 2, budget);
            // cout << "a[i] : " << a[i] << endl;
    // cout << "now : " << now << endl;
        }
        else {
            if (now != a[i]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
