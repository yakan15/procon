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
    ll n,k;cin>>n>>k;
    ll cnt[n]={};
    ll cnt2[n]={};
    vector<ll> a(n);
    rep(i,n){cin>>a.at(i);a[i]--;}
    rep(i,n){
        repr(j,i+1,n){
            if(a[i]>a[j]){
                cnt[i]++;
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(i==j){continue;}
            if(a[i]>a[j]){
                cnt2[i]++;
            }
        }
    }
    ll res=0; 
    rep(i,n){
        res += ll(cnt2[i])*(k*(k-1)/2%MOD);
        res %= MOD;
    }
    rep(i,n){
        res += cnt[i]*k;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
