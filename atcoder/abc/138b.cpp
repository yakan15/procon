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
    double n;cin>>n;
    double res=0;
    rep(i,n){
        double tmp;
        cin>>tmp;
        res += 1.0/tmp;
    }
    printf("%lf\n",1.0/res);
    return 0;
}
