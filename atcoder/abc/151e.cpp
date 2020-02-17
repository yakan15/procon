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

        long long com(int _n, int k){
            if(_n < k){return 0;}
            if(_n < 0 || k < 0){return 0;}
            return fac.at(_n) * (finv.at(k) * finv.at(_n - k) % mod) % mod;
        }

    private:
        int n;
        long long mod;
        vector<long long> fac;
        vector<long long> finv;
        vector<long long> inv;

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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    vector<ll> a(n,0), csum(n+100,0);
    ModCom com(500000, MOD);
    rep(i,n) {
        cin>>a[i];
    }
    if (k==1) {
        cout << 0 << endl;
        return 0;
    }
    sort(begin(a), end(a));
    ll tmp = a[0];
    rep(i,n) {
        a[i] -= tmp;
    }
    ll res = 0;
    ll pls = 0, mns = 0;

    rep(i,n) {
        if (i+k-1<n) {
            DEBUG{
                cout << n-i-1 << " ";
            }
            mns += a[i] * com.com(n-i-1, k-1);
            mns %= MOD;
        }
        if (i-k+1>=0) {
            DEBUG{
                cout <<"ue" << i<< " ";
            }
            pls += a[i] * com.com(i,k-1);
            pls %= MOD;
        }
    }
    res = (pls - mns + MOD) % MOD;
    cout << res << endl;
    return 0;
}
