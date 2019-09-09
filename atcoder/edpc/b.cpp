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
    ll n,k;cin>>n>>k;
    ll h[n];rep(i,n){cin>>h[i];}
    ll dp[n];
    dp[0]=0;
    repr(i,1,n){
        dp[i]=(1LL<<60);
    }
    rep(i,n){
        for(ll j=1;j<=k&&i+j<n;j++){
            dp[i+j]=min(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}
