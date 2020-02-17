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
    ll n,q;cin>>n>>q;
    vector<double> x(n),r(n),h(n),a(q),b(q);
    rep(i,n)cin>>x[i]>>r[i]>>h[i];
    rep(i,q)cin>>a[i]>>b[i];
    function<double(double,double)> calc = [&](
        double radius, double height
    ) {
        return radius * radius * M_PI * height / 3;
    };
    rep(i,q) {
        double res = 0,tmp;
        rep(j,n) {
            double from=x[j],to=x[j]+h[j];
            if (a[i]<=from&&to<=b[i]) {
                res += calc(r[j],h[j]);
            } else if (from <= a[i] && a[i] <= to && to <=b[i]) {
                res += calc(r[j] * (to-a[i])/h[j],to-a[i]);
            } else if (a[i] <= from && from <= b[i] && b[i] <= to) {
                res += calc(r[j],h[j]);
                res -= calc(r[j]*(to-b[i])/h[j], to-b[i]);
            } else if(from <= a[i] && b[i] <= to) {
                res += calc(r[j] * (to-a[i])/ h[j], to-a[i]);
                res -= calc(r[j] * (to-b[i])/h[j], to-b[i]);
            } 
        }
        printf("%.10lf\n",res);
    }
    return 0;
}
