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
    ll n,m,x;
    cin>>n>>m>>x;
    vector<vector<ll>> mat(n,vector<ll>(m));
    vector<ll> c(n);
    rep(i,n) {
        cin>>c[i];
        rep(j,m) {
            cin>>mat[i][j];
        }
    }
    ll res = 1LL<<60;
    rep(i,1<<n) {
        vector<ll> val(m,0);
        ll money = 0;
        rep(j,n) {
            if (i>>j&1) {
                money += c[j];
                rep(k,m) {
                    val[k] += mat[j][k];
                }
            }
        }
        // cout << i << endl;
        // rep(j,n) {
        //     cout << val[i] << " ";
        // }
        // cout << endl;
        // cout << "money " << money << endl;
        bool flg = true;
        rep(j,m) {
            flg &= val[j] >=x;
        }
        if (flg) {
            chmin(res, money);
        }
    }
    cout << ((res == (1LL<<60)) ? -1 : res) << endl;
    return 0;
}
