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
    int n;cin>>n;
    set<int> neighbors[n];
    rep(i,n-1){
        int x,y;cin>>x>>y;
        x--;y--;
        neighbors[x].insert(y);
        neighbors[y].insert(x);
    }
    vector<vector<ll> > dp(2,vector<ll>(n,-1));
    function<ll(int,int,bool)> solve = [&](int now, int parent, bool is_white){
        ll res = 1LL;
        if(dp[is_white][now]!=-1){return dp[is_white][now];}
        if(parent!=-1&&neighbors[now].size()==1){return 1LL;}
        if(parent==-1&&neighbors[now].size()==0){return 1LL;}
        for(auto child: neighbors[now]){
            ll tmp = 0;
            if(child==parent){continue;}
            tmp += solve(child, now, true);
            if(is_white){
                tmp += solve(child, now, false);
            }
            tmp %= MOD;
            res *= tmp;
            res %= MOD;
        }
        DEBUG{
            printf("now: %d, parent: %d, color: %d, res: %lld\n",now,parent,is_white,res);
        }
        DEBUG{cout <<"now: "<<now<<" res : "<< res << endl;}
        return dp[is_white][now] = res;
    };
    ll r = solve(0,-1,true) + solve(0,-1,false);
    r %= MOD;
    cout << r << endl;
    return 0;
}
