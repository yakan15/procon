#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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

class Mod {
    public:
        Mod(int _n, long long _mod){
            assert(_n>=2);
            n = _n+1;
            mod = _mod;
            fac.assign(n,0);
            _finv.assign(n,0);
            _inv.assign(n,0);
            init();
        }

        long long com(int _n, int k){
            if(_n < k){return 0;}
            if(_n < 0 || k < 0){return 0;}
            return fac.at(_n) * (_finv.at(k) * _finv.at(_n - k) % mod) % mod;
        }

        long long inv (int _n) {
            assert(_n<n);
            return _inv.at(_n);
        }

        long long fact (int _n) {
            return fac.at(_n);
        }

        long long finv(int _n) {
            return _finv.at(_n);
        }

    private:
        int n;
        long long mod;
        vector<long long> fac;
        vector<long long> _finv;
        vector<long long> _inv;

        void init(void){
            fac.at(0) = fac.at(1) = 1;
            _finv.at(0) = _finv.at(1) = 1;
            _inv.at(1) = 1;
            for(int i = 2;i < n; i++){
                fac.at(i) = fac.at(i - 1) * i % mod;
                _inv.at(i) = mod - _inv.at(mod % i) * (mod / i) % mod;
                _finv.at(i) = _finv.at(i - 1) * _inv.at(i) % mod;
            }
            return;
        }
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<vector<ll>> nbs(n);
    Mod mod(1e+5 * 3, MOD);
    rep(i,n-1) {
        ll x,y;cin>>x>>y;x--;y--;
        nbs[x].push_back(y);
        nbs[y].push_back(x);
    }
    vector<map<ll,ll>> count(n, map<ll,ll>()), nodes(n,map<ll,ll>());
    vector<ll> parent(n,-1);
    function<ll(ll, ll)> dfs = [&] (ll par,ll num) {
        ll res = 1;
        ll node = 0;
        if (count[par].find(num)!=count[par].end()) {return count[par][num];}
        if (nbs[num].size() == 1) {
            nodes[par][num] = 1;
            return count[par][num] = 1;
        }
        DEBUG{
            cout << num << endl;
        }
        for(auto x:nbs[num]) {
            if (x==par) {continue;}
            parent[x] = num;
            res = res * dfs(num, x) % MOD; 
            res = res * mod.inv(nodes[num][x]) % MOD;
            node += nodes[num][x]; 
        }
        res = res * mod.fact(node) % MOD;
        nodes[par][num] = node+1;
        return count[par][num] = res;
    };
    function<void(ll)> dfs_rev = [&] (ll num) {
        ll res = 1;
        if (nbs[num].size()==1 && parent[num] == nbs[num][0]) {
            return;
        }
        for(auto x:nbs[num]) {
            res = res * mod.finv(nodes[num][x]) % MOD;
            res = res * count[num][x] % MOD;
        }
        for(auto x:nbs[num]) {
            if (parent[num]==x) {continue;}
            nodes[x][num] = n-nodes[num][x];
            ll tmp = res * mod.fact(nodes[x][num]) %MOD;
            tmp = tmp * mod.fact(n-nodes[x][num]-1)%MOD;
            count[x][num] = tmp * mod.inv(count[num][x]) % MOD;
            dfs_rev(x);
        }
        return;
    };
    dfs(-1,0);
    dfs_rev(0);
    rep(i,n) {
        ll res = mod.fact(n-1);
        for(auto x:count[i]) {
            res = res * mod.inv(nodes[i][x.first]) % MOD;
            res = res * x.second % MOD;
        }
        cout << res << endl;
    }
    return 0;
}
