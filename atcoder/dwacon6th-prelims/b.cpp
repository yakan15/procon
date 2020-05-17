#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
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
            _fac.assign(n,0);
            _finv.assign(n,0);
            _inv.assign(n,0);
            init();
        }

        long long com(int _n, int k){
            if(_n < k){return 0;}
            if(_n < 0 || k < 0){return 0;}
            return _fac.at(_n) * (_finv.at(k) * _finv.at(_n - k) % mod) % mod;
        }

        long long fac(int _n) {
            return _fac.at(_n);
        }

        long long inv(int _n) {
            return _inv.at(_n);
        }

        long long finv(int _n) {
            return _finv.at(_n);
        }

    private:
        int n;
        long long mod;
        vector<long long> _fac;
        vector<long long> _finv;
        vector<long long> _inv;

        void init(void){
            _fac.at(0) = _fac.at(1) = 1;
            _finv.at(0) = _finv.at(1) = 1;
            _inv.at(1) = 1;
            for(int i = 2;i < n; i++){
                _fac.at(i) = _fac.at(i - 1) * i % mod;
                _inv.at(i) = mod - _inv.at(mod % i) * (mod / i) % mod;
                _finv.at(i) = _finv.at(i - 1) * _inv.at(i) % mod;
            }
            return;
        }
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin>>N;
    vector<ll> x(N),csum(N+10, 0);
    rep(i,N) {cin>>x[i];}
    ModCom com(N+100, MOD);
    rep(i,N-1) {
        csum[i+1] = (csum[i] + com.fac(N-1) * com.inv(i+1)) % MOD;
    }
    ll res = 0;
    rep(i,N-1) {
        ll d = x[i+1] - x[i];
        res = (res + d * csum[i+1]) % MOD;
    }
    cout << res << endl;
    return 0;
}
