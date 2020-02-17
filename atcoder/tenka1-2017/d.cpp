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
    map<ll,ll> mp;
    vector<pair<ll,ll>> ab;
    rep(i,n){
        ll a,b;cin>>a>>b;
        mp[a] += b;
        ab.emplace_back(a,b);
    }
    function<ll(ll)> solve = [&](ll b){
        ll res;
        if(b>1){res = solve(b-1);}
        else{
            res = 0;
            rep(i,n){
                if((k|ab[i].first)==k){
                    res += ab[i].second;
                }
            }
        }
        if((k>>(b-1)&1)==0){
            return res;
        }
        ll bit = 1LL<<(b-1);
        ll mask = ((1LL<<32)-1)&k^bit|(bit-1);
        DEBUG{
            printf("mask: %lld\n",mask);
        }
        ll tmp=0;
        rep(i,n){
            if((mask|ab[i].first)==mask){
                tmp += ab[i].second;
            }
        }
        return max(res, tmp);
    };
    cout << solve(32) << endl;
    return 0;
}
