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
    ll n,k;
    cin>>n>>k;
    map<ll, ll> mp; 
    rep(i,n){
        ll tmp,tmpb;
        cin>> tmp>>tmpb;
        mp[tmp]+=tmpb;
    }
    for(auto x:mp){
        if(k>x.second){
            k-=x.second;
        }else{
            cout << x.first << endl;
            return 0;
        }
    }
    return 0;
}
