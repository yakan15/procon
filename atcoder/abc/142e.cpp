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
    vector<vector<ll>> key(n,vector<ll>());
    bool chk[n]={};
    ll lim = 1<<30;
    ll cost[1<<14];
    rep(i,1<<14){
        cost[i]=1LL<<40;
    }
    rep(i,m){
        ll a,b;cin>>a>>b;
        ll bit = 0;
        rep(i,b){
            ll tmp;cin>>tmp;
            tmp--;
            chk[tmp]=true;
            key[tmp].push_back(i);
            bit += 1<<tmp;
        }
        chmin(cost[bit],a);
        DEBUG{
            cout << "bit" << endl;
            cout << bit << endl;
            cout << cost[bit] << endl;
        }
    }
    rep(i,n){
        if(!chk[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(k,11){
        repr(i,1,1<<12){
            repr(j,1,1<<12){
                chmin(cost[i|j],cost[i]+cost[j]);
            }
        }
    }
    cout << cost[(1<<n)-1] << endl;
    return 0;
}
