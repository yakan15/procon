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
    ll n,a,b;cin>>n>>a>>b;
    if (n+1<a+b||n>a*b) {
        cout << -1 << endl;
        return 0;
    }

    bool flg = a > b;
    ll mx = max(a,b), mn=min(a,b);
    vector<ll> resv;
    rep(i,mx) {
        resv.push_back(mx-i);
    }
    if (mn==1) {
        if (flg) reverse(begin(resv), end(resv));
        rep(i,resv.size()) {
            cout << resv[i];
            cout << (i==resv.size()-1 ? "\n" : " ");
        }
        return 0;
        
    }
    ll base = mx;
    ll n_splt = (n-mx) / (mn-1);
    ll res = (n-mx) % (mn-1);
    ll cnt = 0;
    while(cnt<mn-1) {
        ll tmp = n_splt;
        if (cnt<res) tmp++;
        base += tmp;
        DEBUG{
            cout << base << endl;
        }
        rep(i,tmp) {
            if (base-i<=n) {
                resv.push_back(base-i);
            }
        }
        cnt++;
    }
    if(flg) {
        reverse(begin(resv), end(resv));
    }
    rep(i,resv.size()) {
        cout << resv[i];
        cout << (i==resv.size()-1 ? "\n" : " ");
    }
    return 0;
}
