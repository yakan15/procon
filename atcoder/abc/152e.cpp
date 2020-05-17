#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}

class ModCom {
    public:
        ModCom(int _n, long long _mod){
            assert(_n>=2);
            n = _n+1;
            mod = _mod;
            fac.assign(n,0);
            finv.assign(n,0);
            inv.assign(n,0);
            init();
        }
        vector<long long> inv;
        vector<long long> fac;
        vector<long long> finv;

        long long com(int _n, int k){
            if(_n < k){return 0;}
            if(_n < 0 || k < 0){return 0;}
            return fac.at(_n) * (finv.at(k) * finv.at(_n - k) % mod) % mod;
        }

    private:
        int n;
        long long mod;

        void init(void){
            fac.at(0) = fac.at(1) = 1;
            finv.at(0) = finv.at(1) = 1;
            inv.at(1) = 1;
            for(int i = 2;i < n; i++){
                fac.at(i) = fac.at(i - 1) * i % mod;
                inv.at(i) = mod - inv.at(mod % i) * (mod / i) % mod;
                finv.at(i) = finv.at(i - 1) * inv.at(i) % mod;
            }
            return;
        }
};

ModCom com(int(1e+6) + 200,MOD);

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

vector<long long> eratosthenes(long long n) {
    vector<long long> ret;
    vector<bool> check(n+100,false);
    if (n<2) {
        return ret;
    }
    long long idx = 2;
    while(idx*idx<=n) {
        if (!check[idx]) {
            ret.push_back(idx);
            for (int i=idx; i<=n; i+=idx) {
                check[i] = true;
            }
        }
        idx++;
    }
    for(int i=idx;i<=n;i++) {
        if (!check[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> a(n);
    vector<ll> ps = eratosthenes(1000000+10);
    vector<ll> mp(1000000+10,0);
    rep(i,n) cin>>a[i];
    rep(i,n) {
        ll target = a[i];
        for(auto x:ps) {
            ll cnt = 0;
            if (x*x>a[i])break;
            while(target%x==0) {
                cnt++;
                target /= x;
            }
            chmax(mp[x], cnt);
        }
        if (target!=1) {
            chmax(mp[target], 1LL);
        }
    }
    ll lcm = 1;
    rep(i,1000000+10){
        if (mp[i]==0)continue;
        lcm *= modpow(i,mp[i],MOD);
        lcm %= MOD;
    }
    ll res = 0;
    rep(i,n) {
        res += lcm * com.inv[a[i]];
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
