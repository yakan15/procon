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
    cin >> n;
    ll a[n]={};
    rep(i,n)cin >> a[i];
    sort(a,a+n);
    ll x,y=0;
    x = a[n-1];
    rep(i,n-1){
        if(y<min(a[i],a[n-1]-a[i]))y=a[i];
        DEBUG{cout << a[i] << endl;cout << y << endl;}

    }
    cout << x << " " << y << endl;
    return 0;
}
