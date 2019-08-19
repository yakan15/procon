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
    ll val[n];
    rep(i,n){
        ll tmp; cin>>tmp; tmp--;
        val[tmp]=i+1;
    }
    ll a[n],b[n];
    a[n-1]=val[n-1],b[n-1]=0;
    for(int i=n-2;i>=0;i--){
        a[i] = a[i+1] +20001;
        b[i] = val[i]-a[i];
    }
    for(int i=n-1;i>=0;i--){
        b[i] -= b[0];
        b[i] += 1;
    }
    rep(i,n){
        cout << b[i];
        if(i==n-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
    rep(i,n){
        cout << a[i];
        if(i==n-1){
            cout << endl;
        }else{
            cout << " ";
        }
    }
    return 0;
}
