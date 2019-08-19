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
    ll n,m;cin>>n>>m;
    vector<ll> edges[n];
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bool selected[n]={}; 
    queue<pair<ll,ll> > que;
    deque<ll> res;
    res.push_front(0);
    selected[0]=true;
    res.push_front(edges[0][0]);
    que.push(make_pair(edges[0][0], 0));
    selected[edges[0][0]]=true;
    if(edges[0].size()>1){
        res.push_back(edges[0][1]);
        que.push(make_pair(edges[0][1],1));
        selected[edges[0][1]]=true;
    }
    while(!que.empty()){
        ll cur,front;
        cur = que.front().first;
        front = que.front().second;
        que.pop();
        for(auto x:edges[cur]){
            if(!selected[x]){
                DEBUG{
                    cout << "now : " << cur << " x : " << x << endl;
                    cout << "front : "<< front << endl;
                }
                if(front){
                    res.push_back(x);
                }else{
                    res.push_front(x);
                }
                que.push(make_pair(x, front));
                selected[x]=true;
                break;
            }
        }
    }
    cout << res.size() << endl;
    while(!res.empty()){
        ll tmp=res.front();
        res.pop_front();
        cout << (tmp+1);
        if(!res.empty()){
            cout<<" ";
        }else{
            cout << endl;
        }
    }
    return 0;
}
