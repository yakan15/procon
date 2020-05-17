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
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) {
        cin>>a[i];
    }
    vector<ll> oddsum(n,0),evensum(n,0);
    ll oddmin=1e+9+100,evenmin = 1e+9+100;
    rep(i,n) {
        if (i%2) {
            oddsum[i/2+1] = oddsum[i/2] + a[i];
            chmin(oddmin, a[i]);
        }
        else {
            evensum[i/2+1] = evensum[i/2] + a[i];
            chmin(evenmin, a[i]);
        }
    }
    if (n%2==0) {
        cout << max(oddsum[n/2], evensum[n/2]) << endl;
        return 0;
    }
    ll res = evensum[n/2+1] - evenmin;
    chmax(res, oddsum[n/2]);
    rep(i,n/2) {
        chmax(res, evensum[i+1] + oddsum[n/2]-oddsum[i+1]);
        chmax(res, oddsum[i+1] + evensum[n/2+1]-evensum[i+2]);
    }
    cout << res << endl;
    return 0;
}
