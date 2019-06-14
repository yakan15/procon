#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,d;
    cin >> n >> d;
    int a2=0,a3=0,a5=0,tmp;
    tmp=d;
    DEBUG{cout << "tmp " << tmp << endl;}
    // if(d==1){
    //     cout << fixed << setprecision(10) << 1.0 << endl;
    //     return 0;
    // }
    while(tmp%2==0){
        tmp /=2;
        a2++;
    }
    while(tmp%3==0){
        tmp /=3;
        a3++;
    }
    while(tmp%5==0){
        tmp /=5;
        a5++;
    }
    DEBUG{printf("i %d, j %d, k %d, tmp %d\n",a2,a3,a5,tmp);}
    if(tmp!=1){
        cout << 0 << endl;
        return 0;
    }
    // DEBUG{cout << "test" << endl;}
    long double dp[70][70][70]={};
    long double prob = (long double)(1)/6;
    DEBUG{cout << "test" << endl;}
    dp[1][0][0]=prob;
    dp[0][1][0]=prob;
    dp[2][0][0]=prob;
    dp[0][0][1]=prob;
    dp[1][1][0]=prob;
    dp[0][0][0]=prob;
    rep(i,n-1)rep(j,a2+1)rep(k,a3+1)rep(l,a5+1){
        // DEBUG{cout << "test" << endl;}
        int jj=69-j,ll=69-l,kk=69-k;
        long double tmp2=0;
        if(jj>=1)tmp2 += dp[jj-1][kk][ll];
        if(jj>=2)tmp2 += dp[jj-2][kk][ll];
        if(jj>=1&&kk>=1) tmp2 += dp[jj-1][kk-1][ll];
        if(kk>=1)tmp2 += dp[jj][kk-1][ll];
        if(ll>=1)tmp2 += dp[jj][kk][ll-1];
        tmp2 += dp[jj][kk][ll];
        dp[jj][kk][ll]=tmp2 / 6.0;
    }
    long double res=0;
    DEBUG{cout << "dp terminated" << endl;}
    for(int i=a2;i<70;i++)for(int j=a3;j<70;j++)for(int k=a5;k<70;k++){
        res += dp[i][j][k];
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
