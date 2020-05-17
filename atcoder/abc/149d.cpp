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
    ll n,k,score[3];
    string t;
    cin>>n>>k>>score[0]>>score[1]>>score[2]>>t;
    map<char, int> mp;
    mp['r'] = score[2];
    mp['s'] = score[0];
    mp['p'] = score[1];
    vector<bool> chk(n,false);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int res = 0;
    rep(i,n) {
        if (i<k) {
            res += mp[t[i]];
            chk[i] = true;
        }
        else {
            if (t[i] != t[i-k] || !chk[i-k]) {
                res += mp[t[i]];
                chk[i] = true;
            }
        }
    }
    cout << res << endl;
    return 0;
}
