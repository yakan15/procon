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
    ll N,C;
    cin >> N >> C;
    ll D[C+1][C+1]={};
    int a=3;
    ll color[a][C+1]={};
    rep(i,C){
        rep(j,C){
            cin >> D[i+1][j+1];
        }
    }
    rep(i,N)rep(j,N){
        ll tmp;
        cin >> tmp;
        color[(i+j)%3][tmp]++;
    }
    ll res=1LL<<60,tmp=0;
    rep(i,C)rep(j,C)rep(k,C){
        tmp=0;
        if(i==j||j==k||k==i)continue;
        for(int l=1;l<=C;l++){
            tmp+=color[0][l]*D[l][i+1];
            tmp+=color[1][l]*D[l][j+1];
            tmp+=color[2][l]*D[l][k+1];
        } 
        res = min(res,tmp);
    }
    cout << res << endl;
    return 0;
}
