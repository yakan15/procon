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


long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

class UnionFind{
    public:
        UnionFind(int N) : parent(N, -1) {}
        bool unite(int x, int y){
            x = find(x);
            y = find(y);
            if (x == y){return false;}
            if (parent[x] > parent[y]){swap(x, y);}
            parent[x] += parent[y];
            parent[y] = x;
        }
        int find(int x) {
            if (parent[x] < 0){return x;}
            return parent[x] = find(parent[x]);
        }
        int size(int x) {
            return -parent[find(x)];
        }
        private:
            vector<int> parent;
};


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> p(n);
    rep(i,n) {
        cin>>p[i];
        if (p[i]!=-1) {
            p[i]--;
        }
    }
    UnionFind uf(n);
    ll conste = 0;
    ll cntm1 = 0;
    ll ngrp = 0;
    set<ll> pars;
    rep(i,n) {
        if (p[i]==-1) {
            cntm1++;
            continue;
        }
        if (uf.find(p[i]) != uf.find(i)) {
            uf.unite(p[i], i);
            conste++;
        }
    }
    ll res = conste * modpow(n-1, cntm1, MOD) % MOD;
    ll rem = n;
    ll sum = 0;
    rep(i,n) {
        if (p[i]!=-1) {
            continue;
        }
        ll ssize = uf.size(i);
        rem -= ssize;
        cout << "rem :" << rem << endl;
        cout << "sum :" << sum << endl;
        ll tmp = modpow(n-1,cntm1-1, MOD) * rem % MOD;
        if (cntm1 > 1) {
            ll tmp2 = modpow(n-1, cntm1-2,MOD) * (n-1-ssize);
            tmp = (tmp +  tmp2 * sum) % MOD;
        }
        res = (res + tmp) % MOD;
        sum += ssize;
    }
    cout << res << endl;
    cout << "res%9" << res % 9 << endl;
    return 0;
}
