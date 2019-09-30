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
    ll n,m;cin>>n>>m;
    vector<ll> a(n);rep(i,n){cin>>a.at(i);}
    priority_queue<double> pq;
    rep(i,n){pq.push(a.at(i));}
    rep(i,m){
        if(pq.empty()){break;}
        double tmp = pq.top();
        pq.pop();
        tmp /=2;
        if(tmp>=1.0){pq.push(tmp);}
    }
    ll res = 0;
    while(!pq.empty()){
        res += ll(pq.top());
        pq.pop();
    }
    cout << res << endl;
    return 0;
}
