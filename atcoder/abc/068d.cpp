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
    ll k; cin>>k;
    vector<ll> a(50,49);
    ll quot = k/50,reminder = k%50;
    rep(i,50){
        a[i] += quot;
        a[i] -= reminder;
    }
    rep(i,reminder){
        a[i] += 50+1;
    }
    cout << 50 << endl;
    rep(i,50){
        cout << a[i] << (i==49 ? "\n" : " ");
    }
    return 0;
}
