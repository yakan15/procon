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
bool chk(int num, int i) {
    return num>>i&1;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w,kk;
    cin>>h>>w>>kk;
    vector<string> s(h);
    rep(i,h) {
        cin>>s[i];
    }
    int sep = 0;
    vector<ll> count, col;
    int res = h+w-2;
    rep(i,1<<(h-1)) {
        bool flg = false;
        int sep_count = 0;
        int row_sep = __builtin_popcount(i);
        count.clear();
        col.clear();
        count.assign(row_sep+1,0);
        col.assign(row_sep+1,0);
        rep(j,w) {
            ll cur = 0;
            rep(ii,row_sep+1) {
                col[ii]=0;
            }
            bool flg2 = true;
            rep(k,h) {
                col[cur] += int(s[k][j]=='1'); 
                if (col[cur]>kk) {
                    flg = true;
                    break;
                }
                if (count[cur]+col[cur]>kk) {
                    sep_count+= flg2;
                    flg2 = false;
                    rep(ii,row_sep+1) {
                        count[ii]=0;
                    }

                }
                if (chk(i, k)) {
                    cur++;
                }

            }
            if (flg) {break;}
            rep(ii,row_sep+1) {
                count[ii]+=col[ii];
            }
        }
        if (flg) {continue;}
        chmin(res,row_sep+sep_count);
    }
    cout << res << endl;
    return 0;
}
