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


class UnionFind{
    public:
        UnionFind(int N) : parent(N, -1) {}
        bool unite(int x, int y){
            x = find(x);
            y = find(y);
            if (x == y){return false;}
            if (parent[x] > parent[y]){swap(x, y);}
            parent[x] += parent[y];
            parent[y] = x;
        }
        int find(int x) {
            if (parent[x] < 0){return x;}
            return parent[x] = find(parent[x]);
        }
        int size(int x) {
            return -parent[find(x)];
        }
        private:
            vector<int> parent;
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    UnionFind uf(n);
    rep(i,n){
        cin>>a[i];
    }
    rep(i,m){
        ll x,y;cin>>x>>y;
        uf.unite(x,y);
    }
    if(n>2*(m+1)){
        cout << "Impossible" << endl;
        return 0;
    }
    if(n==m+1){
        cout << 0 << endl;
        return 0;
    }
    vector<pair<ll,ll>> mins(n, pair<ll,ll>(n+1,1LL<<60));
    rep(i,n){
        ll root = uf.find(i);
        if(chmin(mins[root].second,a[i])){
            mins[root].first = i;
        }
    }
    vector<bool> check(n,false);
    ll res = 0;
    rep(i,n){
        if(mins[i].first!=n+1){
            res += mins[i].second;
            check[mins[i].first]=true;
        }
    }
    vector<ll> unused;
    rep(i,n){
        if(!check[i]){
            unused.push_back(a[i]);
        }
    }
    sort(begin(unused),end(unused));
    rep(i,n-m-2){
        res += unused[i];
    }
    cout << res << endl;
    return 0;
}
