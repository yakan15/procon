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
    int h,w;
    int nn[10][10];
    int d[10][10];
    int cnt[10]={};
    cin >> h>> w;
    rep(i,10)rep(j,10)cin >> nn[i][j];
    rep(i,h)rep(j,w){
        int tmp;
        cin >> tmp;
        if(tmp>=0){
            cnt[tmp]++;
        }
    }
    rep(i,10)rep(j,10){
        d[i][j]=nn[i][j];
    }
    rep(k,10)rep(i,10)rep(j,10){
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    }
    int res=0;
    DEBUG{
        cout << d[2][1] << " " << d[1][2] << endl;
    }
    rep(i,10)res+=cnt[i]*d[i][1];
    cout << res << endl;



    return 0;
}
