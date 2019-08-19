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
    ll a[n+1];
    ll place[n+1];
    rep(i,n){
        cin>>a[i];
        place[a[i]]=i+1;
    }
    set<ll> used;
    used.insert(0);
    used.insert(n+1);
    ll res = 0;
    rep(i,n+1){
        if(i==0){continue;}
        auto it = used.lower_bound(place[i]);
        auto _prev = prev(it);
        ll from = place[i] - *_prev;
        ll to = *it - place[i];
        DEBUG{
            printf("%d from : %lld, to : %lld\n",i,from,to);
        }
        res += from * to * i;
        used.insert(place[i]);
    }
    cout << res << endl;
    return 0;
}
