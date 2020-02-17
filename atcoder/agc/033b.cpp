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
    ll h,w,n;cin>>h>>w>>n;
    ll r0,c0;cin>>r0>>c0;
    string s,t;cin>>s>>t;
    map<char,ll> cnts;
    cnts['L']=c0;
    cnts['R']=w+1-c0;
    cnts['U']=r0;
    cnts['D']=h+1-r0;
    rep(i,n){
        cnts[s[i]]--;
        if(cnts[s[i]]<=0){
            cout << "NO" << endl;
            return 0;
        }
        if(t[i]=='L'&&cnts['R']<w){
            cnts['R']++;
        }else if(t[i]=='R'&&cnts['L']<w){
            cnts['L']++;
        }else if(t[i]=='U'&&cnts['D']<h){
            cnts['D']++;
        }else if(t[i]=='D'&&cnts['U']<h){
            cnts['U']++;
        }
    }
    cout << "YES" << endl;
    return 0;
}
