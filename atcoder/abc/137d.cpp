#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > ab(n,pair<ll,ll>(0,0));
    rep(i,n){cin>>ab[i].first>>ab[i].second;} 
    sort(ab.begin(), ab.end());
    priority_queue<ll> que;
    ll res = 0;
    ll cnt=0;
    for(ll i=1;i<=m;i++){
        while(cnt<n&&ab[cnt].first<=i){
            que.push(ab[cnt].second);
            cnt++;
        }
        if(!que.empty()){
            res += que.top();
            que.pop();
        }
    }
    cout << res << endl;
    return 0;
}
