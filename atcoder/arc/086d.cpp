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
    vector<ll> a(n);
    ll mx=0,idx=0;
    rep(i,n){
        cin>>a[i];
        if(chmax(mx,abs(a[i]))){
            idx = i;
        }
    }
    vector<pair<ll,ll>> res;
    rep(i,n){
        if(i!=idx){
            res.push_back(make_pair(idx,i));
        }
    }
    if(a[idx]>=0){
        rep(i,n-1){
            res.push_back(make_pair(i,i+1));
        }
    }else{
        for(ll i=n-1;i>=1;i--){
            res.push_back(make_pair(i,i-1));
        }
    }
    cout << res.size() << endl;
    rep(i,res.size()){
        cout << res[i].first+1 << " " << res[i].second+1 << endl;
    }
    return 0;
}
