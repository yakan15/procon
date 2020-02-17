#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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
    double a,b,x;cin>>a>>b>>x;
    double height,a_tan;
    if (x <= a*a*b/2) {
        height = 2*x / (a*b);
        a_tan = atan(b/height) * 360;
    }else {
        height = (a*a*b-x) * 2.0 / (a*a);
        a_tan = atan(height/a) * 360;
    }
    printf("%.10lf\n", a_tan / (2 * M_PI));
    return 0;
}
