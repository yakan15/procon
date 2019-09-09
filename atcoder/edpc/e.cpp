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
    vector<ll> w(n),v(n);
    rep(i,n){cin>>w[i]>>v[i];}
    ll lim = 100005;
    vector<vector<ll> > dp(n,vector<ll>(lim,0));
    rep(i,n){
        rep(j,lim){dp.at(i).at(j)=weight+1;}
    }
    dp[0][0]=0;
    dp.at(0).at(v.at(0))=w.at(0);
    repr(i,1,n){
        rep(j,lim){
            dp.at(i).at(j)=dp.at(i-1).at(j);
        }
        repr(j,v.at(i),lim){
            dp.at(i).at(j) = min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    ll res=lim-1;
    while(dp[n-1][res]>weight){res--;}
    cout << res << endl;
    return 0;
}
