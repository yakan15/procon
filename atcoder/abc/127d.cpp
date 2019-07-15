#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
// const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(void) {
    ll n,m;
    cin>>n>>m;
    priority_queue<ll,vector<ll>,greater<ll> > que;
    vector<pair<ll,ll> > bc;
    rep(i,n){
        ll tmp;
        cin>>tmp;
        que.push(tmp);
    }
    rep(i,m){
        ll tmpb,tmpc;
        cin>>tmpb>>tmpc;
        bc.push_back(make_pair(tmpc,tmpb));
    }
    sort(bc.begin(),bc.end(),greater<pair<ll,ll> >());
    int cur=0;
    bool flg=true;
    while(flg){
        rep(i,bc[cur].second){
            ll top = que.top();
            if(top>=bc[cur].first){
                flg=false;
                break;
            }
            que.pop();
            que.push(bc[cur].first);
        }
        if(cur==m-1)break;
        cur++;
    }
    ll res=0;
    while(!que.empty()){
        res+=que.top();
        que.pop();
    }
    cout << res << endl;
    return 0;
}
