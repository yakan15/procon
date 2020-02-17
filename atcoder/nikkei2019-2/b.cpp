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
const ll MOD =998244353;
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
    vector<ll> d(n);rep(i,n)cin>>d[i];
    vector<bool> chk(n+10,false);
    if (d[0] != 0) {
        cout << 0 << endl;
        return 0;
    } 
    sort(begin(d), end(d));
    function<ll(ll,ll)> modpow = [&](ll a, ll b) {
        ll res = 1;
        rep(i,b) {
            res *= a;
            res %= MOD;
        }
        return res;
    };
    ll res = 1;
    ll cur=1,cnt = 0, now = 1,cnt_prev=1;
    while(cur<n) {
        cnt = 0;
        while(cur<n&&d[cur]==now) {
            cnt++;
            cur++;
        }
        res *= modpow(cnt_prev, cnt);
        res %= MOD;
        cnt_prev = cnt;
        now++;
        if (cur==n)break;
        if (now!=d[cur]) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << res << endl;
    return 0;
}
