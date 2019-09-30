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
    ll n;cin>>n;
    vector<ll> a(n);rep(i,n){cin>>a[i];}
    ll dp[n][n];
    ll size[n][n],csum[n+1]={};
    csum[0]=0;
    rep(i,n){csum[i+1]=csum[i]+a.at(i);}
    rep(i,n)repr(j,i,n){
        size[i][j]=csum[j+1]-csum[i];
    }
    rep(i,n)rep(j,n){dp[i][j]=1LL<<60;}
    rep(i,n){dp[i][i]=0;}
    rep(i,n-1){
        dp[i][i+1] = a[i]+a[i+1];
    }

    repr(width,2,n){
        for(int i=0;i+width<n;i++){
            rep(j,width){
                DEBUG{
                    printf("i: %d, i+j: %d, i+w: %d\n",i,i+j,i+width);
                    printf("size : %lld",size[i][i+width]);
                }
                assert(i+width<n);
                assert(i+j+1<=i+width);
                dp[i][i+width] = min(dp[i][i+width],dp[i][i+j]+dp[i+j+1][i+width]+size[i][i+width]);
            } 
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
