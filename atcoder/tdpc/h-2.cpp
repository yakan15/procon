#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    ll n,w,c;cin>>n>>w>>c;
    vector<vector<pair<ll,ll>>> vc(n+1,vector<pair<ll,ll>>());
    for(int i=1;i<=n;i++){
        ll tw,tv,tc;
        cin>>tw>>tv>>tc;
        vc.at(tc-1).push_back(make_pair(tw,tv));
    }
    vector<vector<ll>> dp(c+1,vector<ll>(w+1,0));
    vector<vector<ll>> tmp(c+1,vector<ll>(w+1,0));
    vector<ll> submemo(w+1,0);
    rep(i,n){
        fill(submemo.begin(),submemo.end(),0);
        DEBUG{
            cout << "vc.size : " << vc.at(i).size() << endl;
        }
        for(auto x:vc.at(i)){
            DEBUG{
                cout << "first : " <<x.first<< " second : " << x.second << endl;
            }
            for(int j=x.first;j<=w;j++){
                submemo.at(j) = max(submemo.at(j), submemo.at(j-x.first)+x.second);
            }
        }
        rep(j,c+1){
            rep(k,w+1){
                tmp.at(j).at(k)=dp.at(j).at(k);
            }
        }
        for(int nn=c-1;nn>=0;nn--){
            rep(j,w+1){
                for(int k=j;k<=w;k++){
                    tmp.at(nn+1).at(k) = max(dp[nn+1][k],dp[nn][k]);
                    tmp[nn+1][k] = max(dp[nn+1][k],dp[nn][k-j]+submemo.at(j));
                }
            }
        }
        rep(j,c+1){
            rep(k,w+1){
                dp.at(j).at(k)=tmp.at(j).at(k);
            }
        }
    }
    ll res = 0;
    rep(i,w+1){
        DEBUG{
            if(res<dp[c][i]){
                printf("updated : %lld\n",dp[c][i]);
                printf("i : %d\n",i);
            }
        }
        res = max(res, dp[c][i]);
    }
    cout << res << endl;
    return 0;
}
