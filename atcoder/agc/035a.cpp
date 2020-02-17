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
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n){cin>>a[i];}
    if(n%2){
        int res = 0;
        rep(i,n){
            res ^= a[i];
        }
        cout << (res==0 ? "Yes" : "No") << endl;
    }else{
        int res[2] = {};
        rep(i,n){
            res[i%2] ^= a[i];
        }
        cout << (res[0]==0&&res[1]==0 ? "Yes" : "No") << endl;
    }
    return 0;
}
