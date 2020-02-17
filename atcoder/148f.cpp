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
    int n,u,v;cin>>n>>u>>v;
    u--;v--;
    vector<vector<int>> nbs(n);
    rep(i,n-1) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        nbs[a].push_back(b);
        nbs[b].push_back(a);
    }
    vector<int> du(n,-1), dv(n, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
    que.emplace(0, u);
    while(!que.empty()) {
        int now = que.top().second;
        int d = que.top().first;
        for(auto x:nbs[now]) {
            if (du[x]==-1) {
                du[x] = d+1;
                que.emplace(x,d+1);
            }
        }
    }
    que.emplace(0, v);
    while(!que.empty()) {
        int now = que.top().second;
        int d = que.top().first;
        for(auto x:nbs[now]) {
            if (dv[x]==-1) {
                dv[x] = d+1;
                que.emplace(x,d+1);
            }
        }
    }
    int 
    int res = 
    rep(i,n) {
        if (nbs[i] > 1 && du[i] > dv)
    }
    return 0;
}
