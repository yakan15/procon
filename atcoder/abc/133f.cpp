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
    int n,d;
    cin >> n>>d;
    int a;
    bool p2[100000]={};
    rep(i,100)p2[i*i]=true;
    int x[n][d];
    int res=0;
    rep(i,n)rep(j,d)cin>>x[i][j];
    rep(i,n)for(int j=i+1;j<n;j++){
        a=0;
        rep(k,d){
            a+=abs(x[i][k]-x[j][k])*abs(x[i][k]-x[j][k]);
        }
        DEBUG{cout << a<< endl;}
        if (p2[a])res++;
    }
    cout << res << endl;
    return 0;
}
