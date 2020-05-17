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
    ll h,w,k;
    cin>>h>>w>>k;
    vector<string> s(h);
    rep(i,h)cin>>s[i];
    ll cnt=0;
    ll hh = h,ww=w;
    rep(i,h) rep(j,w) {
        if (s[i][j]=='1') cnt++;
    }
    rep(i,h) {
        ll cnt2 = 0;
        rep(j,w) {
            cnt2 += s[i][j] == '1';
        }
        if (cnt2==0) {
            hh--;
        }
    }
    rep(j,w) {
        ll cnt2 = 0;
        rep(i,h) {
            cnt2 += s[i][j] == '1';
        }
        if (cnt2==0) {
            ww--;
        }
    }
    if (cnt<=k) {
        cout << 0 << endl;
        return 0;
    }
    if (hh%2&&ww%2&&cnt%k==0) {
        cout << cnt/(2*k)+1 << endl;
    }
    else {
        cout << (cnt-1)/(2*k)+1 << endl;
    }
    return 0;
}
