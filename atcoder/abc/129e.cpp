#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
const int MAX = 510000;
ll pow3[MAX],pow2[MAX];

void powinit(void){
    pow3[0]=1;
    rep(i,MAX-1){
        pow3[i+1] = pow3[i]*3;
        pow3[i+1] %= MOD;
    }
    pow2[0]=1;
    rep(i,MAX-1){
        pow2[i+1] = pow2[i]*2;
        pow2[i+1] %= MOD;
    }
}

int main(void) {
    string L;
    cin >> L;
    int n = L.size();
    int cnt=0;
    ll res=0;
    powinit();
    rep(i,n){
        if(L[i]=='1'){
            ll tmp;
            tmp = pow2[cnt];
            tmp *= pow3[n-i-1];
            tmp %=MOD;
            res += tmp;
            res %=MOD;
            cnt++;
        }
    }
    res += pow2[cnt];
    res %= MOD;
    cout << res << endl;
    return 0;
}
