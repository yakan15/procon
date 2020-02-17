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
    int q;cin>>q;
    vector<ull> a(q), b(q);
    ull m,n;
    rep(i,q) cin>>a[i]>>b[i];
    rep(i,q) {
        m = min(a[i],b[i]);
        n = max(a[i],b[i]); 
        ull tmp = sqrtl(m*n-1), res=tmp*2;
        if (m == n) {
            cout << max(m*2-2,0ULL) << endl;
        } else if(m+1==n) {
            cout << max(2*m-2,0ULL) << endl;
        }
        else if (tmp*(tmp+1)>=m*n) {
            cout << max(res-2,0ULL) << endl;
        }else {
            cout << max(res-1,0ULL) << endl;
        }
    }
    return 0;
}
