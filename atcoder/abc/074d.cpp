#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

struct edge{
    ll s,t,w;
    edge(ll s, ll t, ll w) : s(s), t(t), w(w) {}

    bool operator<(const edge &another){
        return w < another.w;
    }
};

// ll check_d[300][300]={};
// // ll mat_dij[300][300];
// set<ll> neighbors[300];
// ll dijkstra(ll from, ll to, ll n){
//     rep(i,n)rep(j,n)mat_dij[i][j]=1LL<<60;
//     rep(i,n)mat_dij[i][i]=0;
//     priority_queue<ll> pq;
//     pq.push(from);
//     do{
//         ll now = pq.top();
//         pq.pop();
//         for(auto i:neighbors[now]){
//             if(mat_dij[from][i]>check_d[from][now]+check_d[now][i]){
//                 mat_dij[from][i]=check_d[from][now]+check_d[now][i];
//                 mat_dij[i][from]=mat_dij[from][i];
//                 DEBUG{printf("push : %lld\n",i);}
//                 pq.push(i);
//             }
//         }
//     }while(!pq.empty());
//     return mat_dij[from][to];
// }

int main(void) {
    ll n;
    cin>>n;
    ll d[n][n];
    ll min_d[n][n];
    rep(i,n)rep(j,n){
        cin >>d[i][j];
        min_d[i][j]=d[i][j];
    }
    rep(k,n)rep(i,n)rep(j,n){
        min_d[i][j]=min(min_d[i][j],min_d[i][k]+min_d[k][j]);
    }
    rep(i,n)rep(j,n){
        if(d[i][j]!=min_d[i][j]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll res=0;
    rep(i,n)rep(j,n){
        ll tmp=1LL<<60;
        rep(k,n){
            if(k==i||k==j)continue;
            tmp=min(tmp, d[i][k]+d[k][j]);
        }
        if(tmp>d[i][j])res+=d[i][j];
    }
    res/=2;
    // vector<edge> edges;
    // rep(i,n)for(ll j=i+1;j<n;j++)edges.push_back(edge(ll(i),ll(j),d[i][j])); 
    // sort(edges.begin(), edges.end());
    // ll res=0;
    // rep(i,n)rep(j,n){
    //     if(i==j)check_d[i][j]=0;
    //     else check_d[i][j]=1LL<<60;
    // }
    // DEBUG{cout << edges.size() << endl;}
    // for(auto e:edges){
    //     // DEBUG{cout << "djikstra : " << dijkstra(e.s,e.t,n)<<endl;}
    //     if(e.w<dijkstra(e.s,e.t,n)){
    //         neighbors[e.s].insert(e.t);
    //         neighbors[e.t].insert(e.s);
    //         check_d[e.s][e.t]=e.w;
    //         check_d[e.t][e.s]=e.w;
    //         res+=e.w;
    //     }
    // }
    cout << res << endl;
    return 0;
}
