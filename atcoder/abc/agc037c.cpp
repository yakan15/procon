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
    ll n;
    cin>>n;
    ll a[n],b[n];
    rep(i,n){
        cin>>b[i];
    }
    rep(i,n){
        cin>>a[i];
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> > ,greater<pair<ll,ll> > > pq;
    rep(i,n){
        ll diff = a[i]-(a[(i+n-1)%n]+a[(i+n+1)%n]+b[i]);
        DEBUG{cout << diff << endl;}
        if(diff>=0){
            pq.push(make_pair(diff,i));
        }
    }
    ll cnt=0;
    DEBUG{
        cout << pq.size() << endl;
    }
    while(!pq.empty()){
        ll cur = pq.top().second;
        ll val = pq.top().first;
        pq.pop();
        cnt+=(a[cur]-b[cur])/(a[(cur-1+n)%n]+a[(cur+1+n)%n]);
        a[cur] = (a[cur]-b[cur])%(a[(cur-1+n)%n]+a[(cur+1+n)%n])+b[cur];
        // a[cur] -= a[(cur-1+n)%n]+a[(cur+1+n)%n];
        DEBUG{
            cout << "cnt : "<<cnt<< " cur : " << cur << " val : "<< val << endl;
        }
        assert(cur>=0&&cur<=n-1);
        for(ll i=cur-1;i<=cur+1;i+=2){
            ll diff = a[(i+n)%n]-(a[(i+n-1)%n]+a[(i+n+1)%n]+b[(i+n)%n]);
            if(diff>=0){
                pq.push(make_pair(diff,(i+n)%n));
            }
        }
    }
    rep(i,n){
        if(a[i]!=b[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
