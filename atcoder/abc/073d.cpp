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
    ll n,m,r;
    cin>>n>>m>>r;
    ll city[n];
    ll dist[n][n];
    rep(i,n)rep(j,n)dist[i][j]=1LL<<60;
    rep(i,r)cin>>city[i];
    rep(i,r)city[i]--;
    rep(i,m){
        ll ts,tt,tw;
        cin >> ts >> tt >> tw;
        tt--;ts--;
        dist[ts][tt]=tw;
        dist[tt][ts]=tw;
    }
    rep(k,n)rep(i,n)rep(j,n){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    }
    ll res=1LL<<60;
    sort(city,city+r);
    do{
        ll tmp=0;
        rep(i,r-1){
            tmp+=dist[city[i+1]][city[i]];
        }
        res=min(res,tmp);
    }while(next_permutation(city, city+r));
    cout << res << endl;
    return 0;
}
