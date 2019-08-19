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
    ll n,d;
    cin>>n>>d;
    int n2=0,n3=0,n5=0;
    vector<vector<vector<vector<long double> > > > dp(101, vector<vector<vector<long double> > >(61, vector<vector<long double> >(41, vector<long double>(28,0))));
    // long double dp[100][60][40][27]={};
    ll tmp=d;
    while(tmp%2==0){
        tmp/=2;
        n2++;
    }
    while(tmp%3==0){
        tmp/=3;
        n3++;
    }
    while(tmp%5==0){
        tmp/=5;
        n5++;
    }
    DEBUG{printf("tmp : %lld\n",tmp);}
    if(tmp!=1){
        cout << 0<< endl;
        return 0;
    }
    int lst[6][3]={
        {0,0,0},
        {1,0,0},
        {0,1,0},
        {2,0,0},
        {0,0,1},
        {1,1,0}
    };
    long double prob=(long double)1/6;
    dp[0][0][0][0]=1;
    rep(i,n)rep(j,n2+1)rep(k,n3+1)rep(l,n5+1){
        rep(h,6){
            dp[i+1][min(n2,j+lst[h][0])][min(n3,k+lst[h][1])][min(n5,l+lst[h][2])]+=dp[i][j][k][l]*prob;
        } 
    }
    printf("%Lf\n",dp[n][n2][n3][n5]);
    return 0;
}
