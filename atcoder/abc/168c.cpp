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
    ll a,b,h,m;cin>>a>>b>>h>>m;
    long double hr = 0.5 * (h * 60 + m);
    long double PI = 3.14159265358979323846264338327950L;
    long double mr = 6.0 * m;
    long double arg = abs(hr-mr);
    arg = min(360.0L-arg,arg);
    // arg = min(180.0L-arg,arg);
    long double res = sqrtl(a*a+b*b-2*a*b*cosl(arg/180.0L*PI));
    printf("%.20Lf\n",res);
    return 0;
}
