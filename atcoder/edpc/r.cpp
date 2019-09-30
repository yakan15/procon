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
vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b, int n){
    vector<vector<ll>> c(n,vector<ll>(n,0));
    rep(i,n)rep(j,n)rep(k,n){ (c[i][k] += a[i][j]*b[j][k]) %= MOD;}
    return c;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    vector<vector<ll>> mat(n,vector<ll>(n)), res(n,vector<ll>(n,0));
    rep(i,n) res[i][i] = 1;
    rep(i,n){
        rep(j,n){
            cin>>mat[i][j];
        }
    }
    while(k){
        if(k&1) {res = mul(res, mat, n);}
        mat = mul(mat, mat, n);
        k /= 2;
    }
    ll ans = 0;
    rep(i,n) rep(j,n) {(ans += res[i][j]) %= MOD;}
    cout << ans << endl;
    return 0;
}
