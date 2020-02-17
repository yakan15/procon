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
    ll n,k;cin>>n>>k;
    vector<ll> a(n), csum(n+1,0);
    map<ll,ll> count;
    rep(i,n){
        cin>>a[i];
        a[i] = (a[i]-1) % k;
    }
    rep(i,n) {
        csum[i+1] = (csum[i] + a[i]) % k;
    }
    ll res = 0;
    rep(i,n) {
        if (i>=k-1){
            count[csum[i+1-k]]--;
        }
        res += count[csum[i+1]];
        count[csum[i+1]]++;
        if (csum[i+1]==0) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
