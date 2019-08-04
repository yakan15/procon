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
    int n,m;
    cin>>n>>m;
    int edges[m][2]={};
    int dist[n][n];
    int inf=1<<25;
    rep(i,m){
        cin>>edges[i][0]>>edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }
    int res=0;
    rep(i,m){
        rep(j,n)rep(k,n)dist[j][k]=inf;
        rep(j,n)dist[j][j]=0;
        rep(j,m){
            if(i==j)continue;
            dist[edges[j][0]][edges[j][1]]=1;
            dist[edges[j][1]][edges[j][0]]=1;
        }
        rep(j,n)rep(k,n)rep(l,n){
            dist[k][l]=min(dist[k][l],dist[k][j]+dist[j][l]);
        }
        bool flg=false;
        rep(j,n)rep(k,n){
            if(dist[j][k]==inf)flg=true;
        }
        res+=int(flg);
    }
    cout << res << endl;
    return 0;

}
