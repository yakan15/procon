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

bool chk(char c1,char c2) {
    return c1=='?' || c2=='?' || c1==c2;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a,b,c;
    cin>>a>>b>>c;
    vector<bool> ab(30000,false), ac(30000,false), bc(30000,false);
    int alen = a.size();
    int blen = b.size();
    int clen = c.size();
    rep(i,alen) rep(j,blen) if (!chk(a[i], b[j])) ab[i-j+15000] = true;
    rep(i,alen) rep(j,clen) if (!chk(a[i], c[j])) ac[i-j+15000] = true;
    rep(i,blen) rep(j,clen) if (!chk(b[i], c[j])) bc[i-j+15000] = true;
    int mx = 2000;
    int ans = 6000;
    for(int i=mx*-2;i<=mx*2;i++) {
        for(int j=mx*-2;j<=mx*2;j++) {
            if (!ab[i+15000]&&!ac[j+15000]&&!bc[j-i+15000]) {
                int l = min(0, min(i,j));
                int r = max(alen, max(blen+i,clen+j));
                chmin(ans, r-l);
            } 
        }
    }
    cout << ans << endl;
    return 0;
}
