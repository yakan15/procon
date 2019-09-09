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
    ll n,weight;cin>>n>>weight;
    vector<ll> w(n),v(n);rep(i,n){cin>>w[i]>>v[i];}
    vector<vector<ll> > dp(n,vector<ll>(100005,0));
    dp.at(0).at(w.at(0))=v.at(0);
    repr(i,1,n){
        rep(j,weight+1){
            dp.at(i).at(j)=dp.at(i-1).at(j);
        }
        for(ll j=w[i];j<=weight;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    ll res=0;
    rep(i,weight+1){
        res = max(res, dp.at(n-1).at(i));
    }
    cout << res << endl;
    return 0;
}
