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
const ll MOD = 998244353;
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
    ll n,a,b,k;cin>>n>>a>>b>>k;
    ModCom com(n+50,MOD);
    vector<pair<ll,ll>> cand;
    rep(i,n+1){
        if(k<a*i){
            continue;
        }
        if((k-a*i)%b==0&&(k-a*i)/b<=n){
            cand.push_back(make_pair(i,(k-a*i)/b));
        }
    }
    ll res = 0;
    for(auto x:cand){
        ll tmp = 1;
        tmp *= com.com(n,x.first);
        tmp *= com.com(n,x.second);
        tmp %= MOD;
        res += tmp;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
