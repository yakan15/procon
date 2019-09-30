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
    int n,m;cin>>n>>m;
    vector<string> a(n),b(m);
    rep(i,n){cin>>a.at(i);}
    rep(i,m){cin>>b.at(i);}
    rep(i,n-m+1){
        rep(j,n-m+1){
            bool flg=true;
            rep(ii,m){
                rep(jj,m){
                    flg &= b[ii][jj]==a[i+ii][j+jj];
                }
            }
            if (flg){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
