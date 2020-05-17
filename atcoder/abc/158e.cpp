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
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,p;
    string s;
    cin>>n>>p>>s;
    map<ll,ll> counts;
    ll res = 0;
    if (p==2||p==5) {
        rep(i,n) {
            ll now = s[i]-'0';
            if (now%p==0) {
                res += i+1;
            }
        }
    }
    else {
        ll rem = 0;
        ll rem10 = 1;
        for(int i=s.size()-1;i>=0;i--) {
            ll now = s[i] - '0';
            rem = (rem + rem10 * now) % p;
            counts[rem]++;
            rem10 = rem10 * 10 % p;
        }
        for(auto x:counts) {
            if (x.first==0) {
                res += x.second * (x.second+1)/2;    
            }
            else {
                res += x.second * (x.second-1)/2;
            }
            
        }
    }
    cout << res << endl;
    return 0;
}
