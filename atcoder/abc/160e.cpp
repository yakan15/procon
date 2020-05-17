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
    ll x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    vector<ll> p(a),q(b),r(c);
    rep(i,a) {cin>>p[i];}
    rep(i,b) {cin>>q[i];}
    rep(i,c) {cin>>r[i];}
    sort(begin(p), end(p), greater<ll>());
    sort(begin(q), end(q), greater<ll>());
    sort(begin(r), end(r), greater<ll>());
    priority_queue<ll, vector<ll>, greater<ll>> pq[2];
    rep(i,x) {
        pq[0].push(p[i]);
    }
    rep(i,y) {
        pq[1].push(q[i]);
    }
    rep(i,c) {
        int idx = 0;
        if (pq[0].top()>=pq[1].top()) {
            idx = 1;
        }
        if (pq[idx].top()<r[i]) {
            pq[idx].pop();
            pq[idx].push(r[i]);
        }
    }
    ll res = 0;
    rep(i,2) {
        while (!pq[i].empty()) {
            res+= pq[i].top();
            pq[i].pop();
        }
    }
    cout << res << endl;
    return 0;
}
