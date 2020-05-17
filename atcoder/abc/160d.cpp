#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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
    ll n,x,y;
    cin>>n>>x>>y;
    x--;y--;
    ll lim = 1e+15;
    vector<vector<ll>> mat(n,vector<ll>(n,lim));
    vector<vector<ll>> nbs(n,vector<ll>());
    rep(i,n) {
        mat[i][i] = 0;
        if (i<n-1) {
            nbs[i].push_back(i+1);
            nbs[i+1].push_back(i);
            mat[i][i+1] = 1;
            mat[i+1][i] = 1;
        }
    }
    mat[x][y] = mat[y][x] = 1;
    nbs[x].push_back(y);
    nbs[y].push_back(x);
    vector<ll> cnt(n+2,0);
    rep(i,n) {
        vector<ll> dist(n,lim);
        dist[i] = 0;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.emplace(0,i);
        while(!pq.empty()) {
            auto now = pq.top();
            pq.pop();
            if (now.first>dist[now.second]) {continue;}
            for(auto x: nbs[now.second]) {
                if (dist[x]>now.first + mat[x][now.second]) {
                    dist[x] = now.first + mat[x][now.second];
                    pq.emplace(dist[x], x);
                }
            }
        } 
        rep(i,n) {
            cnt[dist[i]]++;
        }
    }
    rep(i,n-1) {
        cout << cnt[i+1]/2 << endl;
    }
    return 0;
}
