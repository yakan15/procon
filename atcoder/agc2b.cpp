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
    int balls[n];
    bool flg[n]={};
    rep(i,n){balls[i]=1;}
    flg[0]=true;
    rep(i,m){
        int t,s;
        cin>>t>>s;
        t--;s--;
        balls[s]++;
        if(flg[t]){flg[s]=true;}
        balls[t]--;
        if(balls[t]==0){flg[t]=false;}
    }
    int res=0;
    rep(i,n){
        res += int(flg[i]);
    }
    cout << res << endl;
    return 0;
}
