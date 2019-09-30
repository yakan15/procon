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
    int n;cin>>n;
    vector<int> h(n+1,0),val(n+1,0);rep(i,n){cin>>h[i+1];}
    rep(i,n){cin>>val[i+1];}
    h[0] = 0;
    vector<ll> dp(n+1,-1);
    bool checked[n+1]={};
    vector<set<int>> edges(n+1);
    rep(i,n+1){
        int bound = h[i]; 
        checked[bound]=true;
        while(bound<=n&&checked[bound]){
            bound++;
        }
        int mx = n+1;
        int cur=1;
        while(i+cur<=n){
            if(h[i]<h[i+cur]&&mx>h[i+cur]){
                edges.at(i).insert(i+cur);
                mx = h[i+cur];
            }
            if(h[i+cur]==bound){break;}
            cur++;
        }
    } 
    DEBUG{
        rep(i,n+1){
            for(auto x:edges[i]){
                cout << x<< " ";
            }
            cout << endl;
        }
    }
    function<ll(int)> solve = [&](int cur){
        if(dp[cur]!=-1){return dp[cur];}
        ll res = 0;
        for(auto x:edges[cur]){
            chmax(res, solve(x));
        }
        return dp[cur] = res + val[cur];
    };
    cout << solve(0) << endl;
    return 0;
}
