#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    ll n,m;
    cin >> n >> m;
    vector<ll> cnt;
    unordered_map<ll, ll> mp;

    mp[0]++;
    ll res=0;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        res+=tmp;
        res%=m;
        mp[res]++;
    }
    res=0;
    for(auto x:mp){
        res+=(x.second*(x.second-1))/2;
    }
    cout <<res << endl;
    return 0;
}
