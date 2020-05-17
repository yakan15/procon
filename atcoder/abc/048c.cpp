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
    ll N,X;cin>>N>>X;
    vector<ll> a(N);
    rep(i,N) cin>>a[i];
    ll res = 0;
    rep(i,N) {
        if (a[i]>X) {
            res += a[i]-X;
            a[i] = X;
        }
        if (i>0&&a[i]+a[i-1]>X) {
            res += a[i] + a[i-1] - X;
            a[i] = X - a[i-1];
        }
    } 
    cout << res << endl;
    return 0;
}
