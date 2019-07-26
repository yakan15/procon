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
    int mat[n][n];
    int edge[n][n]={};
    int lim=10000000;
    rep(i,n)rep(j,n)mat[i][j]=lim;
    int next[n][n];
    rep(i,n)rep(j,n)next[i][j]=-1;
    rep(i,n){
        int ta,tb,tc;
        cin>>ta>>tb>>tc;
        ta--;
        tb--;
        mat[ta][tb]=tc;
        mat[tb][ta]=tc;
        edge[ta][tb]=1;
        edge[tb][ta]=1;
    }
    return 0;
}
