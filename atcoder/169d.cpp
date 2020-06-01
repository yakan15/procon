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

map<ll,ll> prime_fact(ll num) {
    ll now = 2;
    map<ll,ll> divisors; 
    if (num<2) {
        return map<ll,ll>();
    }
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


vector<ll> divisors(ll num) {
    ll now = 1;
    vector<ll> divs;
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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    map<ll,ll> d = prime_fact(n);
    ll res = 0;
    vector<ll> csum(100,0);
    rep(i,100) {
        csum[i+1] = csum[i]+i;
    }
    for(auto x:d) {
        auto ptr = upper_bound(all(csum), x.second);
        res += ll(ptr-csum.begin())-2;
    }
    cout << res << endl;
    return 0;
}
