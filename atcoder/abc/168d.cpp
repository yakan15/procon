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


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vector<vector<ll>> edges(n);
    vector<ll> next(n,-1);
    queue<ll> que;
    rep(i,m) {
        ll a,b;cin>>a>>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    que.push(0);
    while(!que.empty()) {
        ll now = que.front();
        que.pop();
        for(auto x:edges[now]) {
            if (next[x]==-1) {
                next[x] = now;
                que.push(x);
            }
        }
    }
    repr(i,1,n) {
        if (next[i]==-1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    repr(i,1,n) {
        cout << next[i]+1<<endl;
    }
    return 0;
}
