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
    ll n,l;cin>>n>>l;
    ll a[n];
    rep(i,n){cin>>a[i];}
    ll cur;
    rep(i,n-1){
        if(a[i]+a[i+1]>=l){
            cur=i+1;
            break;
        }
        if(i==n-2){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    for(int i=1;i<cur;i++){
        cout << i << endl;
    }
    for(int i=n-1;i>cur;i--){
        cout << i << endl;
    }
    cout << cur << endl;
    return 0;
}
