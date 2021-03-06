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
    ll k;cin>>k;
    queue<ll> que;
    repr(i,1,10) {
        que.push(i);
    }
    ll res = 1;
    while(k) {
        res = que.front();
        que.pop();
        ll x = res % 10;
        if (x) {
            que.push(res*10+x-1);
        }
        que.push(res*10+x);
        if (x<9) {
            que.push(res*10+x+1);
        }
        k--;
    }
    cout << res << endl;
    return 0;
}
