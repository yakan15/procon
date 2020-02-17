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
    vector<pair<ll,ll>> ab(n,pair<ll,ll>(0,0));
    ll lim = 1e+9 + 100;
    ll sum = 0, mn=lim;
    rep(i,n) {
        cin>>ab[i].first>>ab[i].second;
        sum += ab[i].first;
        if (ab[i].second < ab[i].first) {
            chmin(mn, ab[i].second);
        }
    }
    if (mn == lim) {
        cout << 0 << endl;
    }
    else {
        cout << sum - mn << endl; 

    }

    return 0;
}
