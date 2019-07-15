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
    ll s, t, w;
    edge(ll s, ll t, ll w) : s(s), t(t), w(w) {}

    bool operator<(const edge &another) const{
        return w < another.w;
    }
};

ll parent[100005]={};
ll root(ll n){
    if(parent[n]==n)return n;
    return parent[n]=root(parent[n]);
}

ll union_(ll a, ll b){
    parent[a]=root(b);
    return root(a);
}

int main(void) {
    int n;
    cin>>n;
    pair<ll,ll> x[n],y[n];
    vector<edge> edges; 
    rep(i,n){
        ll tx,ty;
        cin>>tx>>ty;
        x[i]=make_pair(tx,i);
        y[i]=make_pair(ty,i);
    }
    sort(x,x+n);
    sort(y,y+n);
    DEBUG{
        printf("x : \n");
        rep(i,n){
           cout << x[i].first <<"("<<x[i].second<<")"<< endl; 
        }
        printf("y : \n");
        rep(i,n){
           cout << y[i].first <<"("<<y[i].second<<")"<< endl; 
        }
    }
    rep(i,n-1){
        edges.push_back(edge(x[i].second,x[i+1].second,x[i+1].first-x[i].first));
        edges.push_back(edge(y[i].second,y[i+1].second,y[i+1].first-y[i].first));
    }
    sort(edges.begin(),edges.end());
    DEBUG{
        printf("weights\n");
        rep(i,edges.size()){
            cout << edges[i].w <<" "<< edges[i].s << " " <<edges[i].t<< endl;
        }
    }
    rep(i,100005)parent[i]=i;
    ll res=0;
    for(auto x:edges){
        if(root(x.s)!=root(x.t)){
            res+=x.w;
            union_(x.s,x.t);
        }
    }
    cout << res << endl;
    return 0;
}
