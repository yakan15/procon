#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,q;cin>>n>>q;
    ll a[n];rep(i,n){cin>>a[i];}
    ll x[q];rep(i,q){cin>>x[i];x[i];}
    vector<pair<ll,ll>> wall;
    ll sum=0;
    for(int i=n-1;i>=0;i-=2){
        sum += a[i];
    }
    ll cur=n-2;
    ll cnt=1;
    wall.push_back(make_pair(a[n-1],sum));
    while(cur-cnt>=0){
        sum += a[cur]-a[cur-cnt];
        wall.push_back(make_pair((a[cur]+a[cur-cnt])/2,sum));
        cur--;cnt++;
    }
    sort(wall.begin(), wall.end());
    DEBUG{
        rep(i,wall.size()){
            printf("%lld %lld\n",wall[i].first,wall[i].second);
        }
    }
    rep(i,q){
        auto pointer = lower_bound(wall.begin(),wall.end(),pair<ll,ll>(x[i],0));
        cout << pointer->second << endl;
    }
    return 0;
}
