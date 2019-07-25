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
    ll a[n];
    map<ll,ll, greater<ll> > mp;
    rep(i,n)cin>>a[i];
    rep(i,n)mp[a[i]]++;
    ll ra=0,rb=0;
    for(auto x:mp){
        ll tmp=x.second;
        if(ra!=0&&rb!=0)break;
        if(ra==0)tmp-=2;
        if(ra==0&&tmp>=0){
            ra=x.first;
        }
        if(rb==0)tmp-=2;
        if(rb==0&&tmp>=0)rb=x.first;
    } 
    cout << (ra*rb) << endl;
    return 0;
}
