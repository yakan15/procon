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

vector<ll> divisors(ll num) {
    ll now = 1;
    vector<ll> divs;
    if (num==1) {
        // cout << "return"<<endl;
        divs.push_back(1);
        return divs;
    }
    while(now*now<=num) {
        if (num % now==0) {
            divs.push_back(now);
            if (now*now!=num){
                divs.push_back(num/now);
            }
        }
        now++;
    }
    return divs;
}

map<ll,ll> prime_fact(ll num) {
    ll now = 2;
    map<ll,ll> divisors; 
    while(now*now<=num) {
        while(num%now==0) {
            divisors[now]++;
            num /= now;
        }
        now++;
    }
    if (num != 1) {
        divisors[num]++;
    }
    return divisors;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll res = 0;
    vector<ll> memo(k+100,0);
    // repr(i,1,k+1) {
    for(ll i=k;i>=1;i--) {
        // cout << i << endl;
        ll x = k/i;
        ll count = MOD + modpow(x, n, MOD) - memo[i];
        res = (res + count * i % MOD) % MOD;
        vector<ll> divs = divisors(i);
        // map<ll,ll> primes = prime_fact(i);
        for (auto d:divs) {
            // cout << "d: "<<d.first<< endl; 
            if (d==i) {
                continue;
            }
            memo[d] += count;
            memo[d] %= MOD;
        } 
    }
    cout << res << endl;
    return 0;
}
