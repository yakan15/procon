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
            return true;
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
    ll n;cin>>n;
    vector<ll> x(n),y(n);
    vector<pair<ll,ll>> xs,ys;
    // ll lim = 1000000001;
    // xs.insert(-1);xs.insert(lim);
    // ys.insert(-1);ys.insert(lim);
    rep(i,n){
        cin>>x[i]>>y[i];
        xs.push_back(make_pair(x[i],i));
        ys.push_back(make_pair(y[i],i));
    }
    sort(begin(xs),end(xs));
    sort(begin(ys),end(ys));
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;

    rep(i,n-1){
        pq.push(make_tuple(xs[i+1].first-xs[i].first,xs[i].second, xs[i+1].second));
        pq.push(make_tuple(ys[i+1].first-ys[i].first,ys[i].second, ys[i+1].second));
    }
    UnionFind uf(n);
    ll res = 0;
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        ll dist = get<0>(tp), n1=get<1>(tp), n2=get<2>(tp);
        DEBUG{
            printf("dist: %lld, n1: %lld, n2: %lld\n",dist,n1,n2);
        }
        if(uf.unite(n1,n2)){
            res += dist;
        }
        if(uf.size(n1)==n){
            break;
        }
    }
    cout << res << endl;
    return 0;
}
