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
    ll n,m;
    cin>>n>>m;
    set<ll> from[n], to[n];
    rep(i,m){
        ll tx,ty;cin>>tx>>ty;
        tx--;ty--;
        from[ty].insert(tx);
        to[tx].insert(ty);
    }
    ll dp[1LL<<n];
    rep(i,1LL<<n){
        dp[i] = -1;
    }
    dp[0] = 1;
    function<ll(ll)> solve = [&](ll S){
        DEBUG{
            cout << S << endl;
        }
        if(dp[S]!=-1){return dp[S];} 
        ll res = 0;
        bool isin[n]={};
        // 入ってる要素の確認
        rep(i,n){
            if(!(S>>i&1)){
                isin[i]=true;
            }
        }
        rep(i,n){
            if(S>>i&1){
                bool flg = true;
                for(auto x : from[i]){
                    if(!isin[x]){
                        flg = false;
                        break;
                    }
                }
                if(flg){
                    res += solve(S^(1LL<<i));
                }
            } 
        } 
        return dp[S] = res;
    };
    cout << solve((1LL<<n)-1) << endl;
    return 0;
}
