#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct control{
    ll t;
    bool act;
    ll x;

    control(ll tt, bool tact, ll tx){
        t = tt;act=tact; x=tx;
    }

    bool operator<(const control &another) const{
        if(x!=another.x)return t < another.t;
        else return int(act) < int(another.act);
    }
};

int main(void) {
    ll n,q;
    vector<control> a;
    vector<int> d;
    rep(i,n){
        ll tt,ts,tx;
        cin >> tt >> ts >> tx;
        a.push_back(control(tt-tx,true,tx));
        a.push_back(control(ts-tx,false,tx));
    }
    rep(i,q){
        ll td;
        d.push_back(td);
    }
    sort(a.begin(), a.end());
    set<int> work;
    int cur=0;
    rep(i,q){
        while(a[cur].t<=d[i]){
            if(a[cur].act)work.insert(a[cur].x);
            else work.erase(work.find(a[cur].x));
            cur++;
        }
        if(work.size()==0)cout << -1 << endl;
        else cout << *work.begin() << endl;
    }
    return 0;
}
