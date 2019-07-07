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
    cin >>n >>m;
    int ne = 3*n;
    vector<int> edges[ne+1];
    int s,t;
    rep(i,m){
        int u,v;
        cin >> u >> v;
        rep(i,3){
            edges[u+i*n].push_back(v+((i+1)%3)*n);
        }
    }
    cin >> s >> t;
    int d[ne+1];
    rep(i,ne+1){
        if(i==s)d[i]=0;
        else d[i]=1LL<<30;
    }
    int value = s;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    do {
        if(!que.empty())que.pop();
        DEBUG{cout << "value " << value << endl;}
        for(auto x:edges[value]){
            if (d[value]+1<d[x]){
                d[x]=d[value]+1;
                que.push(make_pair(d[value]+1,x));
            }
        }
        if(!que.empty()){
        DEBUG{
            cout << "top " << que.top().second << endl;
        }
            value = que.top().second;
        }
    } while(!que.empty());
    cout << ((d[t]==1LL<<30) ? -1 : d[t]/3) << endl; 
    return 0;
}
