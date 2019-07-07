#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
// WA
int main(void) {
    ll n,m;
    cin >> n >> m;
    ll l[m],r[m],d[m];
    vector<pair<ll, ll> > neighbor[n+1];
    ll place[n+1];
    ll inf = 1LL<<60;
    rep(i,n+1)place[i]=inf;
    rep(i,m)cin >> l[i] >> r[i] >> d[i];
    rep(i,m){
        neighbor[min(l[i],r[i])].push_back(make_pair(max(l[i],r[i]),(l[i]<r[i]) ? d[i] : (d[i]*-1)));
    }
    rep(i,n+1){
        if(place[i]!=inf){
            continue;
        } 
        place[i]=0;
        queue<ll> que;
        que.push(i);
        while(!que.empty()){
            ll cur = que.front();
            DEBUG{cout << "cur " << cur << endl;}
            que.pop();
            for(auto x:neighbor[cur]){
                DEBUG{
                    cout << "p " << place[x.first] << " nxt " << place[cur]+x.second << endl;
                }
                if(place[x.first]!=inf&&place[x.first]!=place[cur]+x.second){
                    cout << "No" << endl;
                    return 0;
                } 
                if(place[x.first]==inf){
                    que.push(x.first);
                    place[x.first]=place[cur]+x.second;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
