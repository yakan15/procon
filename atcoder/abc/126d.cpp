#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
vector<unordered_map<int, int> >edges;
vector<int>colors;

void dfs(int n){
    DEBUG{
        cout << n << endl;
    }
    for(auto x:edges[n]){
      if(colors[x.first]!=-1){
          continue;
      } 
      if(x.second%2==1)colors[x.first]=1-colors[n];
      else colors[x.first]=colors[n];
      dfs(x.first);
    }
    // for(auto x:edges[n]){
    //     if(colors[x.first]==-1)dfs(x.first);
    // }
}

int main(void) {
    cin >> n;
    colors = vector<int>(n+1,-1);
    edges = vector<unordered_map<int, int> >(n+1, unordered_map<int,int>());
    int start=n+1;
    rep(i,n-1){
        int tu,tv,tw;
        cin >> tu >> tv >> tw;
        start = min(start, min(tu,tv));
        edges[tu][tv]=tw;
        edges[tv][tu]=tw; 
    }
    DEBUG{
        cout << "start " << start << endl;
    }
    colors[start]=0;
    dfs(start);
    rep(i,n){
        cout << colors[i+1] << endl;
    }

    return 0;
}
