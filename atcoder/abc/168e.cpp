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


string pairtos(ll a, ll b) {
    return to_string(a) + " " + to_string(b);
}

pair<ll,ll> keytoll(string s) {
    string delim = " ";
    ll delimidx = s.find(delim);
    ll a = stoll(s.substr(0,delimidx));
    ll b = stoll(s.substr(delimidx+1, s.size()-delimidx));
    return pair<ll,ll>(a,b);
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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    unordered_map<string,ll> mp;
    unordered_map<string,ll> mpcnt;
    ll cnt00 = 0;
    ll cnta0 = 0,cntb0=0;
    rep(i,n) {
        cin>>a[i]>>b[i];
        if (a[i]==0 && b[i]==0) {
            cnt00++;
            continue;
        }
        else if (a[i]==0) {
            cnta0++;
            continue;
        }
        else if (b[i]==0) {
            cntb0++;
            continue;
        }
        ll x = __gcd(abs(a[i]),abs(b[i]));
        a[i] /= x;
        b[i] /= x;
        if (a[i]<0) {
            a[i] *= -1;
            b[i] *= -1;
        }
        string st = pairtos(a[i],b[i]);
        mp[st]++;
    }
    ll res = 1;
    for (auto x:mp) {
        // cout <<"mp:"<< x.first << endl;
        // cout <<"check"  << mpcnt[x.first] << endl;
        if (mpcnt.find(x.first)!=mpcnt.end()) {
            // cout << "continue" << endl;
            continue;
        }
        ll tmp = modpow(2, x.second, MOD);
        auto p = keytoll(x.first);
        string rev;
        if (p.second<0) {
            rev = pairtos(p.second*-1,p.first);
        }
        else {
            rev = pairtos(p.second, p.first*-1);
        }
        // cout << "rev:" << rev << endl;
        if (mp.find(rev)!=mp.end()) {

            tmp += modpow(2,mp[rev],MOD)-1;
            mpcnt[rev]=1;
        }
        tmp %= MOD;
        // cout << x.first << " " << tmp << endl;
        res = (res * tmp) % MOD;
    }
    if (cnta0 > 0 || cntb0 > 0) {
        ll tmp = modpow(2, cnta0, MOD);
        tmp += modpow(2, cntb0, MOD)-1;
        tmp %= MOD;
        res = (res * tmp) % MOD;
    }
    res = (res - 1 + cnt00 + MOD) % MOD;
    cout << res << endl;

    return 0;
}
