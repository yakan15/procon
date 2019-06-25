#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007LL;


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

ll n,m;
map<ll,ll> pf;


void prime_factors(ll n){
    ll cnt=2;
    while(n!=1&&cnt*cnt<=n){ 
        while(n%cnt==0){
            pf[cnt]++;
            n/=cnt;
        }
        cnt++;
    }
    if(n!=1)pf[n]=1;
    return;
}

int main(void) {
    cin >> n >> m;
    COMinit();
    prime_factors(m);
    DEBUG{
        for(auto x:pf){
            printf("n : %lld, t : %lld\n",x.first, x.second);
        }
    }
    ll res=1;
    for(auto x:pf){
        res *= COM(x.second+n-1,n-1);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
