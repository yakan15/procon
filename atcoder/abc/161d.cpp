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
    ll k;cin>>k;
    vector<vector<ll>> dp(11,vector<ll>(10,0));
    vector<ll> colsum(11,0),cumsum(11,0);
    if (k<=9) {
        cout << k << endl;
        return 0;
    }
    rep(i,10) {
        dp[0][i] = 1;
    }
    rep(i,10) {
        rep(j,10) {
            for(int k=-1;k<=1;k++) {
                if (j+k>=0&&j+k<=9) {
                    dp[i+1][j] += dp[i][j+k];
                }
            }
        }
    }
    rep(i,10) {
        rep(j,10) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    rep(i,10) {
        repr(j,1,10) {
            colsum[i] += dp[i][j];
        }
    } 
    ll s = 0;
    rep(i,10) {
        s += colsum[i];
        cout << colsum[i] << "(" << s << ")" << " ";
    }
    ll col = 0;
    while(k>=colsum[col]) {
        k -= colsum[col];
        col++;
    }
    ll row = 1;
    while(k>dp[col][row]) {
        k -= dp[col][row];
        row++;
    }
    ll res = row;
    while(col>0) {
            res *=10;
        if(row>0&&dp[col-1][row-1]>=k) {
            res += --row;
        } else if (row < 9 && dp[col-1][row-1]+dp[col-1][row] <k) {
            res += ++row;
            k -= dp[col-1][row-1] + dp[col-1][row];
        } else {
            res += row;
            k -= dp[col-1][row-1];
        }
        cout << k << endl;
        col--;
    }
    cout << res << endl;
    return 0;
}
