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
    ll n;cin>>n;
    string s;
    vector<ll> a;
    cin>>s;
    rep(i,n) {
        if (s[i]=='R') {
            a.push_back(0);
        }
        else if (s[i]=='G') {
            a.push_back(1);
        }
        else {
            a.push_back(2);
        }
    }
    vector<vector<ll>> csum(3,vector<ll>(n+40));
    rep(i,n) {
        rep(j,3) {
            csum[j][i+1] = csum[j][i];
        }
        csum[a[i]][i+1]++;
    }
    ll res = 0;
    rep(i,n) {
        repr(j,i+1,n) {
            if (a[i]!=a[j]) {
                ll cur = 3 - a[i] - a[j];
                res += csum[cur][n] - csum[cur][j];
                if (2*j-i<n&&a[2*j-i]==cur) {
                    res--;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
