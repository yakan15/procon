#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
int parent[2][200005];
void ufinit(void){
    rep(i,2)rep(j,200005){
        parent[i][j]=j;
    }
}

int root(int a, int n){
    if(parent[a][n]==n){return n;}
    return parent[a][n] = root(a, parent[a][n]);
}

void unite(int a, int x, int y){
    if(root(a, x)!=root(a, y)){
        parent[a][root(a, x)] = root(a, y);
        root(a, x);
        root(a, y);
    }
}

string ptos(int a, int b){
    return "a"+to_string(a)+"b"+to_string(b);
}

int main(void) {
    int n,k,l;
    cin>>n>>k>>l;
    int p[k],q[k],r[l],s[l];
    rep(i,k){cin>>p[i]>>q[i];}
    rep(i,l){cin>>r[i]>>s[i];}
    unordered_map<string, int> counts;
    ufinit();
    rep(i,k){
        unite(0, p[i], q[i]);
    }
    rep(i,l){
        unite(1, r[i], s[i]);
    }
    for(int i=1;i<=n;i++){
        DEBUG{cout << ptos(root(0, i), root(1, i)) << endl;}
        counts[ptos(root(0, i), root(1, i))]++;
    }
    for(int i=1;i<=n;i++){
        cout << counts[ptos(root(0, i), root(1, i))];
        if(i<n){cout << " ";}
        else { cout << endl;}
    }
    return 0;
}
