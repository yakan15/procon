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
    ll n,k;
    cin >> n >> k;
    vector<vector<vector<ll> > > count(k, vector<vector<ll> >(k,vector<ll>(2,0)));
    vector<vector<vector<ll> > > sum(k, vector<vector<ll> >(k,vector<ll>(2,0)));
    rep(i,k)rep(j,k){
    }
    rep(i,n){
        ll tx,ty,tc;
        char c;
        cin >> tx >> ty >> c;
        if(c=='W')tc=0;
        else tc=1;
        ll cnt=0;
        cnt += tx/k;
        cnt += ty/k;
        if(cnt%2==1)tc=1-tc;
        DEBUG{
            cout << endl << tx%k << " " << ty%k << " " << tc << endl;
        }
        count[tx%k][ty%k][tc]++;
    }
    rep(i,2)sum[0][0][i]=count[0][0][i];
    rep(i,k)rep(j,k)rep(l,2){
        if(i>0&&j==0)count[i][j][l]+=count[i-1][j][l];
        if(j>0&&i==0)count[i][j][l]+=count[i][j-1][l];
        if(j>0&&i>0)count[i][j][l]+=count[i-1][j][l]+count[i][j-1][l]-count[i-1][j-1][l];
    }
    ll res=0;
    DEBUG{cout << count[k-1][k-1][1]<<endl;}
    rep(i,k)rep(j,k)rep(l,2){
        ll cnt=0,tmp=0;
        tmp += count[k-1][k-1][l];
        if(i>0){
            tmp+=count[i-1][k-1][1-l]-count[i-1][k-1][l];
            cnt++;
        }
        if(j>0){
            tmp+= count[k-1][j-1][1-l]-count[k-1][j-1][l];
            cnt++;
        }
        if(cnt==2){
            tmp+= count[i-1][j-1][l]*2-count[i-1][j-1][1-l];
        }
        DEBUG{
            cout << "i " << i << " j " << j << " l " << l<< endl;
            cout << "sum " << tmp << endl;
        }
        res=max(res,tmp);
    }
    cout << res << endl;
    return 0;
    
}
