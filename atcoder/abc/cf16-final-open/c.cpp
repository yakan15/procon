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


int main(void) {
    int n,m;cin>>n>>m;
    UnionFind uf(n+m);    
    rep(i,n){
        int k;
        cin>>k;
        rep(j,k){
            int tmp;cin>>tmp;
            uf.unite(i,tmp+n-1);
        }
    }
    int root = uf.find(0);
    rep(i,n){
       if(root != uf.find(i)){
           cout << "NO" << endl;
           return 0;
       }
    }
    cout << "YES" << endl;
    return 0;
}
