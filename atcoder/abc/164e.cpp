#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
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

struct nt {
    ll time;
    ll node;
    ll money;
    nt(ll t, ll n, ll m) : time(t), node(n), money(m) {}
};

struct conNt {
    bool operator()(nt const &a, nt const &b) {
        return a.time > b.time;
    }
};


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,s;
    cin>>n>>m>>s;
    ll lim = 1LL<<60;
    vector<vector<ll>> mata(n,vector<ll>(n,lim));
    vector<vector<ll>> matb(n,vector<ll>(n,lim));
    vector<ll> exc(n), exctime(n);
    vector<vector<ll>> time(n,vector<ll>(2501, lim));
    rep(i,m) {
        ll u,v,a,b;
        cin>>u>>v>>a>>b;u--;v--; 
        mata[u][v] = mata[v][u] = a;
        matb[u][v] = matb[v][u] = b;
    }
    rep(i,n) {
        cin>>exc[i]>>exctime[i];
    }
    priority_queue<nt, vector<nt>, conNt> pq;
    pq.emplace(0,0,min(2500LL, s));
    ll nxt_time, remain;
    while (!pq.empty()) {
        nt now = pq.top();
        pq.pop();
        if (time[now.node][now.money] < now.time) {
            continue;
        }
        rep(i,n) {
            nxt_time = now.time + matb[now.node][i];
            remain = now.money - mata[now.node][i];
            if (remain >= 0 &&
            nxt_time < time[i][remain]) {
                time[i][remain] = nxt_time;
                pq.emplace(nxt_time, i, remain);
            }
        }
        nxt_time = now.time + exctime[now.node];
        remain = min(2500LL, now.money + exc[now.node]);
        if (time[now.node][remain] > nxt_time) {
            time[now.node][remain] = nxt_time;
            pq.emplace(nxt_time, now.node, remain);
        }
    }

    repr(i, 1, n) {
        ll res = lim;
        rep(j,2500) {
            chmin(res, time[i][j]);
        }
        cout << res << endl;
    }
    return 0;
}
