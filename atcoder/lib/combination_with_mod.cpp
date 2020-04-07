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


/*
参考（ほぼそのまま）: http://drken1215.hatenablog.com/entry/2018/06/08/210000
*/
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
    // test : https://atcoder.jp/contests/abc132/tasks/abc132_d
    cin.tie(0);
    ios::sync_with_stdio(false);
    ModCom com(100000,MOD);
    int n,k;
    cin >> n >> k;
    ll res;
    rep(i,k+1){
        if(i==0)continue;
        res = com.com(n-k+1,i);
        if(k!=i)res *= com.com(k-1,k-i);
        res %= MOD;
        cout << res << endl;
    }
    return 0;
}
