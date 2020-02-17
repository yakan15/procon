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
    string s;cin>>s;
    ll n = s.size();
    n++;
    vector<ll> a(n,-1);
    rep(i,n){
        if ( i == 0 &&  s[i] == '<') {
            a[i] = 0; 
        } else if(i == n-1 && s[i-1] == '>') {
            a[i] = 0;
        } else if(s[i-1] == '>' && s[i] == '<') {
            a[i] = 0;
        }
    }
    ll now=0;
    rep(i,n) {
        if (a[i] == 0) now=0;
        else if(i!=0&&s[i-1]=='<') {
            now++;
            a[i] = now;
        }
    }
    now = 0;
    for(int i=n-1;i>=0;i--) {
        if (a[i] == 0) now = 0;
        else if (i!=n-1&&s[i]=='>') {
            now++;
            chmax(a[i], now);
        }
    }
    if (s[0] == '>') a[0] = a[1]+1;
    if (s[n-1] == '<') a[n-1] = a[n-2]+1;
    ll res = 0;
    rep(i,n) {res += a[i];}
    cout << res << endl;
    return 0;

}
