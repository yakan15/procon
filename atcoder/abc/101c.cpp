#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
int n,m,q;
int main(void) {
    cin >> n >> m >> q;
    int lst[n+1][n+1]={};
    int sum[n+1][n+1]={};    
    rep(i,m){
        int l,r;
        cin >> l >> r;
        lst[l][r]++;
    }
    rep(i,n+1)rep(j,n+1){
        if(j==0)continue;
        sum[i][j]=sum[i][j-1]+lst[i][j];
    }
    int input[q][2]={};
    rep(i,q){
        cin >> input[i][0] >> input[i][1];
    }
    rep(i,q){
        int res=0;
        for(int j=input[i][0];j<=input[i][1];j++){
            res+=sum[j][input[i][1]]-sum[j][input[i][0]-1];
        }        
        cout << res << endl;
    }
    return 0;
}
