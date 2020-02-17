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
    ll n;cin>>n;
    vector<ll> a(n);rep(i,n){cin>>a[i];}
    ll cnt = 1;
    ll res = 0;
    rep(i,n){
        if(a[i]==cnt){
            cnt++;
        }else if(cnt==1){
            res += a[i] - 1;
            cnt++;
        }else{

            res += a[i]/cnt;
            if(a[i]%cnt==0){
                res--;
            }
        }
    }
    cout << res << endl;
    return 0;
}
