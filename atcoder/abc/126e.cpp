#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
const int MAX = 200005;
int parent[MAX];

void parinit(void){
    rep(i,MAX){parent[i]=i;}
}

int root(int a){
    if(parent[a]==a){return a;}
    return parent[a] = root(parent[a]);
}

void unite(int a, int b){
   parent[root(a)] = root(b); 
}

int main(void) {
    int n,m;
    cin>>n>>m;
    parinit();
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        unite(x,y);
    }
    set<int> roots;
    for(int i=1;i<=n;i++){
        roots.insert(root(i));
    }
    cout << roots.size() << endl;
    return 0;
}
