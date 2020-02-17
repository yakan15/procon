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
    ll m;cin>>m;
    ll res = -1;
    ll cum = 0;
    rep(i,m) {
        ll d,c;cin>>d>>c;
        ll x = cum + c * d;
        res += c;
        cum += c * d;
    }
    DEBUG{
        cout << res << endl;
    }
    ll a = 0;
    while(cum >= 10) {
        DEBUG{
            cout << cum << endl;
        }
        res += cum / 10;
        a = cum % 10;
        cum = cum / 10 + a;
    }
    cout << res << endl;
    return 0;
}
