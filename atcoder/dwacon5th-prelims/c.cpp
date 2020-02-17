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
    int n,q;cin>>n;
    string s;cin>>s>>q;
    vector<int> D,M;
    vector<int> cumsum(n+5,0);
    rep(i,n) {
        if(s[i]=='D') {
            D.push_back(i);
        }
        if(s[i]=='M') {
            M.push_back(i);
        }
        cumsum[i+1] = cumsum[i] + int(s[i]=='C');
    }
    vector<pair<int,int>> start;
    for(auto d:D) {
        auto it = lower_bound(begin(M), end(M), d);
        if(it != M.end()) {
            start.emplace_back(d, *it);
        }
    }
    rep(i,q) {
        int res = 0;
        int k;cin>>k;
        for(auto s:start) {
            res += cumsum[max(n,s.first+k-1)] - cumsum[s.second];
        }
        cout << res << endl;
    }
    return 0;
}
