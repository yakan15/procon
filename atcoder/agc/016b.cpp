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
    if(a[0]+1<a[n-1]){
        cout << "No" << endl;
        return 0;
    }
    // int cnt = a[0];
    // bool flg = a[0]==a[n-1]&&(a[0]==n-1||n>=2*a[0]) ||
    // cnt<n-1&&a[n-1]==cnt+1&&a[cnt]==cnt+1&&a[cnt-1]==cnt;
    bool flg = a[0]==a[n-1]&&(a[0]==n-1||n>=2*a[0]);
    if(!flg&&a[0]==a[n-1]){
        cout << "No" << endl;
        return 0;
    }else if(a[0]==a[n-1]){
        cout << "Yes" << endl;
        return 0;
    }
    int sm_cnt=0;
    int sm = a[0];
    int cur=0;
    while(cur<n&&a[cur]==sm){
        cur++;sm_cnt++;
    }
    flg |= n-sm_cnt-(a[n-1]-sm_cnt)*2>=0&&sm_cnt<a[n-1];
    cout << (flg ? "Yes" : "No") << endl;
    return 0;
}
