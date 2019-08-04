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
    int lim=10000000;
    int x[m], y[m], d[m];
    rep(i,n)rep(j,n)mat[i][j]=lim;
    rep(i,m){
        int ta,tb,tc;
        cin>>ta>>tb>>tc;
        ta--;
        tb--;
        x[i] = ta;
        y[i] = tb;
        d[i] = tc;
        mat[ta][tb]=tc;
        mat[tb][ta]=tc;
    }
    rep(k,n)rep(i,n)rep(j,n){
        if(mat[i][j]>mat[i][k]+mat[k][j]){
            mat[i][j]=mat[i][k]+mat[k][j];
        }
    }
    int res=0;
    rep(i,m){
        if(d[i] > mat[x[i]][y[i]]){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
