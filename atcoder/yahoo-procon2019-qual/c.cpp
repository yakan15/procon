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
    ll k,a,b;cin>>k>>a>>b;
    if((b-a)/2<2||a>k+1){
        cout << k+1 << endl;
        return 0;
    }else{
        ll remain = k;
        ll res = a;
        remain -= a-1;
        res += (b-a)*(remain/2);
        res += remain%2;
        cout << res << endl;
    }
    return 0;
}
