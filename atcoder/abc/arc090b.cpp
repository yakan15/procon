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
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > edges[n];
    bool flg[n]={};
    ll inf = 1LL<<60;
    ll place[n];
    rep(i,n){place[i]=inf;}
    rep(i,m){
        ll l,r,d;
        cin>>l>>r>>d;
        l--;r--;
        edges[r].push_back(make_pair(l,d));
        edges[l].push_back(make_pair(r,-d));
    }
    ll cur=0;
    queue<ll> que;
    while(cur<n){
        DEBUG{cout << cur << endl;}
        place[cur]=0;
        flg[cur]=true;
        que.push(cur);
        while(!que.empty()){
            ll now = que.front();
            for(auto x:edges[now]){
                if(place[x.first]==inf){
                    que.push(x.first);
                    place[x.first]=place[now]+x.second;
                    flg[x.first]=true;
                }else if(place[x.first]!=place[now]+x.second){
                    printf("No\n");
                    return 0;
                }
            }
            que.pop();
        }
        while(cur<n&&flg[cur]){
            cur++;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
