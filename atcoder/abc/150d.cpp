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

ll lcm(ll a, ll b) {
    return a* b / __gcd(a,b);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vector<ll> a(n);rep(i,n){
        cin>>a[i];
        a[i] /= 2;
    }
    sort(begin(a), end(a), greater<ll>());
    ll tmp = 1;
    rep(i,n) {
        tmp = lcm(tmp, a[i]);
    }
    rep(i,n) {
        if (tmp/a[i]%2==0) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll res = m/tmp;
    cout << (res%2 ? res/2+1:res/2) << endl;

    return 0;
}
