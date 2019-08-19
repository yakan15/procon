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
    int a[5];
    rep(i,5){cin>>a[i];}
    int res=0;
    int aa=10;
    rep(i,5){
        if(a[i]%10==0){
            res += a[i];
        }else{
            res += (a[i]/10+1)*10;
            aa = min(aa,a[i]%10);
        }
    }
    if(aa!=10){
        res += aa;
        res -=10;
    }
    cout << res << endl;
    return 0;
}
