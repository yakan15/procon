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
    ll n,m,s,t;cin>>n>>m>>s>>t;
    s--;t--;
    vector<vector<pair<ll,ll>>> yen_nbs(n),sn_nbs(n);
    rep(i,m){
        ll u,v,a,b;cin>>u>>v>>a>>b;
        u--;v--;
        yen_nbs[u].push_back(make_pair(v,a)); 
        yen_nbs[v].push_back(make_pair(u,a)); 
        sn_nbs[u].push_back(make_pair(v,b)); 
        sn_nbs[v].push_back(make_pair(u,b)); 
    }
    DEBUG{
        cout <<"test" << endl;
    }
    vector<ll> d_yen(n,1LL<<60),d_sn(n,1LL<<60);
    d_yen[s]=0;d_sn[t]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        ll now = pq.top().second;
        pq.pop();
        for(auto x:yen_nbs[now]){
            if(chmin(d_yen[x.first],d_yen[now]+x.second)){
                DEBUG{

                    cout <<"in: "<< x.first << endl;
                }
                pq.push(make_pair(d_yen[x.first], x.first));
            }
        }
    }
    DEBUG{
        cout <<"test" << endl;
        cout << "size: "<< pq.size() << endl;
    }
    pq.push(make_pair(0,t));
    while(!pq.empty()){
        ll now = pq.top().second;
        pq.pop();
        for(auto x:sn_nbs[now]){
            if(chmin(d_sn[x.first],d_sn[now]+x.second)){
                DEBUG{

                    cout <<"in: "<< x.first << endl;
                }
                pq.push(make_pair(d_sn[x.first], x.first));
            }
        }
    }
    rep(i,n){
        pq.push(make_pair(d_yen[i]+d_sn[i],i));
    }
    rep(i,n){
        while(pq.top().second<i){
            pq.pop();
        }
        cout << (1000000000000000LL-pq.top().first) << endl;
    }
    return 0;
}
