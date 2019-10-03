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
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    sort(begin(a), end(a));
    int cnt = a[0];
    if(cnt>=n){
        cout << "No" << endl;
        return 0;
    }
    vector<int> num(n);
    int col = 1;
    num[0] = 1;
    bool fig = false;
    repr(i, 1, n){
        num[i] = col;
        if(col==cnt){
            flg = true;
        }
        col = min(col+1, cnt);
    }
    repr(i,1,n){
        if(a[i]==col+1) {
            
        }
    }
    cout << "Yes" << endl;
    return 0;
}
