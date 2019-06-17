#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,q;
struct tsx {
    ll s;
    ll t;
    ll x;
    tsx(ll ts, ll tt, ll tx){
        s = ts;
        t = tt;
        x = tx;
    }
    bool operator<(const tsx &another) const{
        return t < another.t;
    }
};
int main(void) {
    cin >> n>> q;
    vector<ll> d;
    vector<tsx> a;
    
    rep(i,n){
        ll ts,tt,tx;
        cin >> ts >> tt >> tx;
        a.push_back(tsx(ts-tx,tt-tx,tx));
    }
    sort(a.begin(), a.end());
    rep(i,q){
        ll td;
        cin >> td;
        d.push_back(td);
    }
        DEBUG{printf("tese\n");}
    int cur_min=0;
    rep(i,q){
        // DEBUG{printf("tese\n");}
        int cur=cur_min;
        ll tmp=(1LL<<40);
        while(a.size()>cur&&a[cur].s<=d[i]){
            if(a[cur].t<=d[i]){
                // a.erase(a.begin()+cur);
                // continue;
                cur_min=cur;
            }else tmp = min(tmp, a[cur].x);
            cur++;
        }
        if(tmp==(1LL<<40))cout << -1 << endl;
        else cout << tmp << endl;
    }
    return 0;
}
