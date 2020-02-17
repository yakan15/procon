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
    ll n,m;cin>>n>>m;
    if (m < 2*n || 4*n < m) {
        cout << "-1 -1 -1" << endl;
        return 0;
    }
    vector<ll> cnt(n,2);
    ll res = 2 * n;
    rep(dummy,2) {
        if(res==m)break;
        rep(i,n) {
            cnt[i]++;
            res++;
            if(res==m)break;
        }
    }
    ll ncnt[3]={};
    rep(i,n)ncnt[cnt[i]-2]++;
    printf("%lld %lld %lld\n", ncnt[0], ncnt[1], ncnt[2]);
    return 0;
}
