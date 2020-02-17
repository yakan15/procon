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
    int n = s.size();
    if(s[n-1]=='1'||s[0]=='0'){
        cout << -1 << endl;
        return 0;
    }
    rep(i,n-1){
        if(s[i]!=s[n-i-2]){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<pair<int,int>> edges;
    int source = 1;
    int target = 2;
    int cnt = 2;
    repr(i,0,n){
        target = i+2;
        edges.push_back(make_pair(source,target));
        if(s[i]=='1'){
            source = i+2;
        }
    }
    rep(i,n-1){
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    return 0;
}
