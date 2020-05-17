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
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    ll cur = n;
    ll cnt = m;
    vector<ll> res;
    if (m==1) {
        rep(i,n) {
            if (s[i]=='1') {
                cout << -1 << endl;
                return 0;
            }
        }
        rep(i,n) {
            cout << 1 << ((i==n-1) ? "\n" : " ");
        }
        return 0;
    }
    while(cur>0) {
        if (cur<cnt) {
            cnt--;
            continue;
        }
        if (s[cur-cnt]=='0') {
            res.push_back(cnt);
            cur -= cnt;
            cnt = m;
        } 
        else {
            cnt--;
        }
        if (cnt==1) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(all(res));
    rep(i,res.size()) {
        cout << res[i] << ((i==res.size()-1) ? "\n" : " ");
    }
    return 0;
}
