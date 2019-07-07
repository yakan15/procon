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
    int n,k;
    cin >> n >> k;
    int lim = 2*k;
    vector<vector<ll> > count(lim,vector<ll>(lim,0));
    vector<vector<ll> > sum(lim,vector<ll>(lim,0));
    rep(i,n){
        int tx,ty;
        char c;
        cin >> tx >> ty >> c;
        if(c=='W')tx+=k;
        count[tx%lim][ty%lim]++;
    }
    sum[0][0]=count[0][0];
    rep(i,lim)rep(j,lim){
        if(i>0&&j>0)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        else if(i>0)sum[i][j]=sum[i-1][j];
        else sum[i][j]=sum[i][j-1];
    }
    int res=0;
    rep(i,k)rep(j,k){
        int tmp=0;
        int center=0;
        center=sum[i+k-1][j+k-1];
        if(i>0&&j>0)center=-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1];
        else if(i>0)center=-sum[i-1][j+k-1];
        else if(j>0)center=-sum[i+k-1][j-1];
        tmp+=center;
        tmp+=sum[lim-1][lim-1]-sum[i+k-1][lim-1]-sum[lim-1][j+k-1]+center;
        if(j>0)tmp+=sum[lim-1][j-1]-sum[i+k-1][j-1];
        if(i>0)tmp+=sum[i-1][lim-1]-sum[i-1][j+k-1];
        if(i>0&&j>0)tmp+=sum[i-1][j-1];
        res=max(tmp,res);
    }
    cout << res << endl;
    return 0;
}
