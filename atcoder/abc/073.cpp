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
    rep(i,n)cin>>a[i];
    unordered_map<ll,ll> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    int res=0;
    for(auto x:mp){
        DEBUG{cout << " first : "<<x.first << " second : "<<x.second << endl;}
        if(x.second%2)res++;
    }
    cout << res << endl;
    return 0;
}
