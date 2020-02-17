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
    ll n,m;cin>>n>>m;
    ll lim = 1000000000000000;
    vector<map<ll,ll>> edges(n,map<ll,ll>());
    rep(i,n-1) {
        edges[i+1][i] = 0;
    }
    rep(i,m) {
        ll l,r,c;
        cin>>l>>r>>c;
        l--;r--;
        if (edges[l].find(r) == edges[l].end()) {
            edges[l][r] = c;
        } else {
            chmin(edges[l][r], c);
        }
    } 
    vector<ll> d(n, lim), chk(n,0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    d[0] = 0;
    pq.emplace(0, 0);
    while(!pq.empty()) {
        auto top = pq.top();
        ll now = top.second;
        ll dist = top.first;
        pq.pop();
        if (chk[now]!=0) continue;
        chk[now] = 1;
        for(auto x: edges[now]) {
            if (chmin(d[x.first], d[now] + x.second)) {
                pq.emplace(d[x.first], x.first);
            }
        }
    }
    cout << (d[n-1] == lim ? -1 : d[n-1]) << endl;
    return 0;
}
