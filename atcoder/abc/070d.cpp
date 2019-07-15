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
    ll n;
    cin>>n;
    vector<pair<ll,ll> > neighbors[n];
    ll d[n];
    rep(i,n)d[i]=1LL<<60;
    rep(i,n-1){
        ll ts,tt,tw;
        cin>>ts>>tt>>tw;
        ts--;tt--;
        neighbors[ts].push_back(make_pair(tt,tw));
        neighbors[tt].push_back(make_pair(ts,tw));
    }
    DEBUG{printf("graph end\n");}
    ll q,k;
    cin>>q>>k;
    k--;
    d[k]=0;
    ll query[q][2];
    rep(i,q){
        cin>>query[i][0]>>query[i][1];
    }
    priority_queue<ll> pq;
    pq.push(k);
    DEBUG{printf("dijkstra start\n");}
    while(!pq.empty()){
        ll now = pq.top();
        pq.pop();
        for(auto x:neighbors[now]){
            if(d[x.first]>d[now]+x.second){
                pq.push(x.first);
                d[x.first]=d[now]+x.second;
                d[x.first]=d[x.first];
            }
        }
    }
    rep(i,q){
        cout << (d[query[i][0]-1]+d[query[i][1]-1]) << endl;
    }
    return 0;
}
