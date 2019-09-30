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
    ll n;cin>>n;
    vector<ll> a(n);rep(i,n) {cin>>a[i];}
    ll sum = 0;
    rep(i,n) {
        sum += a[i];
    }
    if(a.size()==1){
        cout << a[0] << endl;
    }
    else if(a[n-1]>=0){
        cout << sum << endl;
    }else{
        cout << max(a[0],sum-a[n-1]) << endl;
    }
    return 0;
}
