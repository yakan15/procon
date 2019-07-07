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
    ll n,c;
    cin >> n >> c;
    vector<pair<ll, ll> > xv;
    rep(i,n){
        ll tx,tv;
        cin >> tx >> tv;
        xv.push_back(make_pair(tx,tv));
    }
    vector<pair<ll, ll> > xv_rev;
    for(int i=n-1;i>=0;i--){
        xv_rev.push_back(make_pair(c-xv[i].first,xv[i].second));
    }
    vector<pair<ll,ll> > max_a,max_b;
    ll tmp=0,dist=0,now=0;
    max_a.push_back(make_pair(0,0));
    max_b.push_back(make_pair(0,0));
    rep(i,n){
        now = now + xv[i].second - (i==0 ? xv[i].first : (xv[i].first - xv[i-1].first));
        if(tmp<now){
            tmp=now;
            dist=xv[i].first;
        }
        max_a.push_back(make_pair(tmp,dist));
    }
    tmp=0;dist=0;now=0;
    rep(i,n){
        now = now + xv_rev[i].second - (i==0 ? xv_rev[i].first : (xv_rev[i].first - xv_rev[i-1].first));
        if(tmp<now){
            tmp=now;
            dist=xv_rev[i].first;
        }
        max_b.push_back(make_pair(tmp,dist));
    }
    ll res=0;
    rep(i,n+1){
        tmp = max_a[i].first+max_b[n-i].first - min(max_a[i].second,max_b[n-i].second);
        tmp = max(tmp, max(max_b[n-i].first, max_a[i].first));
        res = max(res,tmp);
    }
    cout << res << endl;
    return 0;
}
