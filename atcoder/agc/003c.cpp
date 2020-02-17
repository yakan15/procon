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
    vector<pair<int,int>> a(n,pair<int,int>(0,0));
    rep(i,n){cin>>a[i].first;a[i].second = i;}
    sort(begin(a),end(a));
    int cnt[2] = {};
    rep(i,n){
        if(a[i].second%2 != i%2) {
            cnt[i%2]++;
        }
    }
    cout << max(cnt[0], cnt[1]) << endl;

    return 0;
}
