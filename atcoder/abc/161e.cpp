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
    ll n,k,c;cin>>n>>k>>c;
    string s;
    cin>>s;
    vector<ll> fw(k,-1),bk(k,-1);
    ll cnt = 0;
    rep(i,n) {
        if (s[i]=='x') {
            continue;
        }
        if (cnt==0) {
            fw[0] = i;
            ++cnt;
        }
        else if (fw[cnt-1]+c<i) {
            fw[cnt] = i;
            ++cnt;
        }
        if (cnt==k) break;
    }

    cnt--;
    for(int i=n-1;i>=0;i--) {
        if (s[i]=='x') continue;
        if (cnt==k-1) {
            bk[k-1] = i;
            --cnt;
        }
        else if (bk[cnt+1]-c>i) {
            bk[cnt] = i;
            --cnt;
        }
        if (cnt==-1) break;
    }
    rep(i,k) {
        if (fw[i]==bk[i]) {
            cout << fw[i]+1 << endl;
        }
    }
    return 0;
}
