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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<set<int> > edges(n+1,set<int>());
    bool is_target[n+1]={};
    rep(i,m){
        int s,t;cin>>s>>t;
        edges.at(s).insert(t);
        is_target[t]=true; 
    }
    repr(i,1,n+1){
        if(!is_target[i]){edges.at(0).insert(i);}
    }
    int memo[n+1];
    rep(i,n+1){memo[i]=-1;}
    function<int(int)> solve = [&](int source){
        if(memo[source]!=-1){return memo[source];}
        int res=0;
        if(edges[source].size()==0){return memo[source]=0;}
        for(auto target:edges[source]){
            res = max(res, solve(target));
        }
        return memo[source] = res + 1;
    };
    cout << solve(0)-1 << endl;
    return 0;
}
