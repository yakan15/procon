#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
vector<ll> a;
vector<pair<ll,ll> > bc;
int main(void) {
    cin >> n >> m;
    rep(i,n){
        ll ta;
        cin >> ta;
        a.push_back(ta);
    }
    rep(i,m){
        ll tb,tc;
        cin >> tc >> tb;
        bc.push_back(make_pair(tb,tc));
    }
    sort(a.begin(),a.end());
    sort(bc.begin(),bc.end(),greater<pair<ll,ll>>());
    for(auto x:bc){
        auto lb = lower_bound(a.begin(), a.end(),x.first);
        if(lb==a.begin())break;
        else lb--;
        rep(i,x.second){
            *lb=x.first;
            if(lb==a.begin())break;
            lb--;
        }
    }
    ll res=0;
    DEBUG{
        for(auto x:a){
            printf("%lld\n",x);
        }
    }
    for(auto x:a){
        res += x;
    }
    cout << res << endl;
    return 0;
}
