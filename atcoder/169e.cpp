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
    vector<ll> a(n),b(n);
    rep(i,n) {
        cin>>a[i]>>b[i];
    }
    sort(all(a));
    sort(all(b));
    if (n%2) {
        ll mn = a[n/2];
        ll mx = b[n-1-(n/2)];
        cout << mx-mn+1 << endl;
    }
    else {
        ll mx = b[n/2] + b[n/2-1];
        ll mn = a[n/2] + a[n/2-1];
        cout << mx - mn + 1 << endl;
    }

    return 0;
}
