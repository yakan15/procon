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
    int n,k,m;
    cin>>n>>k>>m;
    int now = 0;
    rep(i,n-1) {
        int tmp;cin>>tmp;
        now += tmp;
    }
    if (n * m <= now) {
        cout << 0 << endl;
    } else if (n * m > now + k) {
        cout << -1 << endl;
    }
    else {
        cout << n * m - now << endl;
    }
    return 0;
}
