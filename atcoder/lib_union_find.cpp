#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

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

/* verified by atcoder abc 120 D
   https://atcoder.jp/contests/abc120/tasks/abc120_d */
int main(void) {
    ll n,m;
    cin>>n>>m;
    int a[m],b[m];;
    ll res[m];
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    ll now=n*(n-1)/2;
    UnionFind uf(n);
    for(int i=m-1;i>=0;i--){
        res[i]=now;
        if(uf.find(a[i])!=uf.find(b[i])){
            now -=ll(uf.size(a[i]))*uf.size(b[i]);
            uf.unite(a[i],b[i]);
        }
    }
    rep(i,m){
        cout << res[i] << endl;
    }
    return 0;
}
