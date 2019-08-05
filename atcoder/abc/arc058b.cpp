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
///////combination///////
ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
////////////////////////
int main(void) {
    ll h,w;
    cin>>h>>w;
    ll a,b;
    cin>>a>>b;
    COMinit();
    ll res=0;
    for(int i=0;i<=h-1-a;i++){
        ll tmp=COM(i+b-1,b-1);
        if(i+b-1==0&&b==0)tmp=1;
        tmp *= COM(h-1-i+w-b-1,w-b-1);
        tmp%=MOD;
        res+=tmp;
        res %=MOD;
    }
    cout << res << endl;
    return 0;
}
