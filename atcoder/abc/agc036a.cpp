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
    ll s;cin>>s;
    ll x[3][2];
    x[0][0]=x[0][1]=0;
    x[1][0]=1e+9;
    x[1][1]=1;
    x[2][1] = s/x[1][0]+1;
    x[2][0] = x[1][0] - s%x[1][0];
    if(s==ll(1e+18)){
        x[1][1]--;x[2][1]--;
    }
    rep(i,3){
        rep(j,2){
            cout << x[i][j];
            if(i==2&&j==1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
    return 0;
}
