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
    string s,t;
    cin>>s>>t;
    int ns = s.size(),nt=t.size();
    int sum_s[ns+1]={},sum_t[nt+1]={};
    rep(i,ns){
        sum_s[i+1] = (s[i]=='A' ? 2 : 1) + sum_s[i];
    }
    rep(i,nt){
        sum_t[i+1] = (t[i]=='A' ? 2 : 1) + sum_t[i];
    }
    int q;cin>>q;
    rep(i,q){
        int a,b,c,d;cin>>a>>b>>c>>d;
        a--;c--;
        cout << ((sum_s[b]-sum_s[a])%3 == (sum_t[d]-sum_t[c])%3 ? "YES" : "NO") << endl;
    }
    return 0;
}
