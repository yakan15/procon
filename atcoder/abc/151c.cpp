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
    vector<int> cnt(n+5,0);
    int ans = 0;
    int pena = 0;
    rep(i,m) {
        int a;string res;
        cin>>a>>res;
        if (cnt[a] == -1) continue;
        else if (res == "WA") cnt[a]++;
        else {
            ans++;
            pena += cnt[a];
            cnt[a] = -1;
        }
    }
    cout << ans << " "  << pena << endl;
    return 0;
}
