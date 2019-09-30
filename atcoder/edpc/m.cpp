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
    vector<ll> a(n);rep(i,n){cin>>a.at(i);}
    vector<vector<ll> > dp(n+1,vector<ll>(k+1,0));
    dp.at(0).at(k)=1;
    rep(i,n){
        dp.at(i+1).at(k) = dp.at(i).at(k);
        for(ll j=k-1;j>=0;j--){
            dp.at(i+1).at(j) += dp.at(i+1).at(j+1);
            dp.at(i+1).at(j) += dp.at(i).at(j);
            dp.at(i+1).at(j) %= MOD;
            if(j<k-a.at(i)){
                dp.at(i+1).at(j) += (MOD-dp.at(i).at(j+a.at(i)+1));
                dp.at(i+1).at(j) %= MOD;
            }
        }
    }
    DEBUG{
        rep(i,n){
            rep(j,k+1){
                cout << dp[i+1][j] <<" ";
            }
            cout << endl;
        }
    }
    cout << dp.at(n).at(0) << endl;
    return 0;
}
