#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll l;

struct edge {
    ll from,to,weight;
    edge(ll from, ll to, ll weight) : from(from), to(to), weight(weight){}
};

int main(void) {
    cin >> l;
    vector<edge> e;
    ll cnt;
    ll max_n=0;
    for(cnt=1;(1LL<<cnt)<=l;cnt++){
       e.push_back(edge(cnt,cnt+1,0)); 
       e.push_back(edge(cnt,cnt+1,(1LL<<cnt-1))); 
        max_n+=1LL<<cnt-1;
    }
    ll cur;
    while(max_n!=l-1){
        cur=log2(l-max_n-1)+1;
        DEBUG{
            cout << cur << endl;
        }
        e.push_back(edge(cur,cnt,max_n+1));
        max_n+=(1LL<<cur-1);
    }
    cout << cnt << " " << e.size() << endl;
    for(auto x:e){
        printf("%lld %lld %lld\n",x.from, x.to, x.weight);
    }

    return 0;
}
