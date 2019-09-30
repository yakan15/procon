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
    ll w,h;cin>>w>>h;
    ll p[w],q[h];rep(i,w){cin>>p[i];}
    rep(i,h){cin>>q[i];}
    vector<pair<ll,ll>> cost;
    rep(i,w){cost.push_back(make_pair(p[i],1));}
    rep(i,h){cost.push_back(make_pair(q[i],0));}
    sort(begin(cost), end(cost));
    ll cntw=w+1,cnth=h+1;
    ll req = (w+1)*(h+1)-1;
    ll res = 0;
    rep(i,cost.size()){
        if(req==0){break;}
        if(cost.at(i).second==1){
            if(cnth>0&&cnth<=req){ 
                res += cost.at(i).first*cnth;
                req -= cnth;
                cntw--;
            }
        }else{
            if(cntw>0&&cntw<=req){
                res += cost.at(i).first*cntw;
                req -= cntw;
                cnth--;
            }
        }
    }
    cout << res << endl;
    return 0;
}
