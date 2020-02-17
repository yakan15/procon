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
    ll n;cin>>n;
    ll gsb[2][3];
    bool flg[3] = {};
    rep(i,2) {
        rep(j,3) {
            cin>>gsb[i][j];
        }
    }
    rep(i,3) {
        flg[i] = gsb[0][i] < gsb[1][i];
    }
    ll res = 0;
    if (flg[0]==flg[1]&&flg[1]==flg[2]) {
        int from = flg[0] ? 0 : 1;
        int to = 1-from;
        rep(i,n+1) {
            rep(j,n-i+1) {
                ll tmp = 0;
                tmp += i % gsb[from][0] + i / gsb[from][0] * gsb[to][0];
                tmp += j % gsb[from][1] + j / gsb[from][1] * gsb[to][1];
                tmp += (n-i-j) % gsb[from][2] + (n-j-i) / gsb[from][2] * gsb[to][2];
                chmax(res, tmp);
            }
        }
    } else {
        vector<int> ab, ba;
        rep(i,3) {
            if(flg[i]) ab.push_back(i);
            else ba.push_back(i);
        }
        ll tmp = 0;
        if (ab.size()==2) {
            DEBUG{
                cout << "pattern2" << endl;
            }
            rep(i,n+1) {
                ll tmp2 = 0;
                tmp2 += i % gsb[0][ab[0]] + i / gsb[0][ab[0]] * gsb[1][ab[0]];
                tmp2 += (n-i) % gsb[0][ab[1]] +  (n-i) / gsb[0][ab[1]] * gsb[1][ab[1]];
                chmax(tmp, tmp2);
            }
            res = tmp % gsb[1][ba[0]] + tmp / gsb[1][ba[0]] * gsb[0][ba[0]];
        } else {
            DEBUG{
                cout << "pattern3" << endl;
            }
            tmp = n % gsb[0][ab[0]] + n / gsb[0][ab[0]] * gsb[1][ab[0]];
            rep(i,tmp+1) {
                ll tmp2 = 0;
                tmp2 += i % gsb[1][ba[0]] + i / gsb[1][ba[0]] * gsb[0][ba[0]];
                tmp2 += (tmp-i) % gsb[1][ba[1]] +  (tmp-i) / gsb[1][ba[1]] * gsb[0][ba[1]];
                chmax(res, tmp2);
            }
        }
    }
    cout << res << endl;
    return 0;
}
