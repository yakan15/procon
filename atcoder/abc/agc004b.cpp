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
    ll n,x;
    cin>>n>>x;
    ll a[n];
    ll time[n];
    ll lim = 1LL<<60;
    ll dif[n]={};
    ll from[n]={};
    rep(i,n){cin>>a[i];}
    rep(i,n){time[i]=a[i];}
    rep(i,n){from[i]=a[i];}
    rep(i,n){
        rep(j,n){
            if(time[(i+j)%n]>a[i]+x*j){
                time[(i+j)%n] = a[i]+x*j;
                dif[(i+j)%n] = x*j;
                from[(i+j)%n] = a[i];
            }
        }
    }
    ll res=0;
    rep(i,n){
        DEBUG{cout << dif[i] << endl;}
        res = max(res, dif[i]);  
    }
    rep(i,n){
        res += from[i];
    }
    cout << res << endl;
    return 0;
}
