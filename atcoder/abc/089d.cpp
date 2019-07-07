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
    ll h,w,d;
    cin >> h>> w>> d;
    vector<pair<ll, ll> > grid(h*w+1, pair<ll, ll>(0,0));
    ll sum[d][h*w/d+2]={};
    rep(i,h)rep(j,w){
        ll tmp;
        cin >> tmp;
        grid[tmp].first=i;
        grid[tmp].second=j;
    }
    ll q;
    cin >> q;
    ll lr[q][2];
    rep(i,q)cin >> lr[i][0] >> lr[i][1];
    rep(i,d){
        for(ll j=0;i+(j+1)*d<=h*w;j++){
            sum[i][j+1]=sum[i][j]+abs(grid[i+j*d].first-grid[i+(j+1)*d].first)+abs(grid[i+j*d].second-grid[i+(j+1)*d].second);
        }
    }
    rep(i,q){
        DEBUG{
            printf("from : %lld, to : %lld\n",lr[i][0],lr[i][1]);
        }
        cout << sum[lr[i][1]%d][lr[i][1]/d] - sum[lr[i][0]%d][lr[i][0]/d] << endl;
    } 
    return 0;
}
