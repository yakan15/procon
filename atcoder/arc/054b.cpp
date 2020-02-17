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
    long double p;cin>>p;
    int n = 200;
    vector<long double> speed(n);
    speed[0] = 1;
    repr(i,1,n) {
        speed[i] = max((long double)(0), pow((long double)(2),(long double)(i)/1.5));
    }
    long double res = LDBL_MAX;
    rep(i,n) {
        if (speed[i] != 0) {
            chmin(res, (long double)(i)+p/speed[i]);
        }
    }
    printf("%.10Lf\n", res);
    return 0;
}
