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
        if(x==another.x&&t==another.t)return int(act) < int(another.act);
        return t < another.t;
    }
};

int main(void) {
    ll n,q;
    cin >> n >> q;
    vector<control> a;
    vector<ll> d;
    rep(i,n){
        ll tt,ts,tx;
        cin >> tt >> ts >> tx;
        a.push_back(control(tt-tx,true,tx));
        a.push_back(control(ts-tx,false,tx));
    }
    rep(i,q){
        ll td;
        cin >> td;
        d.push_back(td);
    }
    sort(a.begin(), a.end());
    set<ll> work;
    ll cur=0;
    rep(i,q){
        while(cur<n*2&&a[cur].t<=d[i]){
            if(a[cur].act)work.insert(a[cur].x);
            else work.erase(a[cur].x);
            cur++;
        }
        if(work.empty()) cout << -1 << endl;
        else cout << *(work.begin()) << endl;
    }
    return 0;
}
