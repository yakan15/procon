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
    ll n;cin>>n;
    ll a[n];
    rep(i,n){cin>>a[i];}
    sort(a,a+n);
    ll val=a[0], cur=0;
    for(int i=1;i<n;i++){
        if(val*2>=a[i]){
            val += a[i];
        }else{
            val += a[i];
            cur= i;
        }
    }
    cout << n-cur << endl;
    return 0;
}
