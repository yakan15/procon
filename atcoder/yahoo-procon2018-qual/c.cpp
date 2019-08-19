#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;


int main(void) {
    ll n;cin>>n;
    vector<ll> x(n),c(n),v(n);
    vector<pair<ll,ll> > vc(n+2,pair<ll,ll>(0,0));
    vector<vector<ll> > dp(n+1,vector<ll>(1<<n,0));
    rep(i,n){cin>>x.at(i);}
    rep(i,n){cin>>vc.at(i).second;}
    rep(i,n){cin>>vc.at(i).first;}
    // vector<ll> res(n,0);
    vector<ll> budget(n+1,0);  
    for(ll i=1;i<=n;i++){
        budget.at(i) += x.at(i-1);
        for(ll j=1;j<(1<<n);j++){
            ll cost = 0,value=0;
            rep(k,n){
                if(j>>k&1){
                    cost += vc.at(k).second;
                    value += vc.at(k).first; 
                }
            } 
            dp.at(i).at(j) = (cost <= budget.at(i) ? value : 0);
        }
    }
    rep(i,n){
        rep(j,1<<n){
            if(__builtin_popcount(j)<=n-i){
                rep(k,n){
                    if((j>>k)&1){
                        dp[i][j] = max(dp[i][j], dp[i][j^(1LL<<k)]);
                    }
                }
            }
        }
    }
    map<pair<ll,ll>,ll> memo;
    function<ll(ll,ll)> solve = [&](ll a,ll b){
        if(memo.count(pair<ll,ll>(a,b))) return memo[pair<ll,ll>(a,b)];
        if(a==n){return 0LL;}
        ll res = dp[a][b];
        ll tmp = 1LL<<60;
        rep(i,n){
            if((b>>i)&1){
                tmp = min(tmp, solve(a+1, b^(1<<i)));
            }
        }
        return memo[make_pair(a,b)] = max(res, tmp);
    };
    cout << solve(0,(1LL<<n)-1) << endl;
    return 0;
}
