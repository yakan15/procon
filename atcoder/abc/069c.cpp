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
    ll cnt4=0,cntodd=0;
    rep(i,n)cin>>a[i];
    rep(i,n){
        if(a[i]%2)cntodd++;
        else if(a[i]%4==0)cnt4++;
    }
    if(cntodd<=cnt4||cntodd==cnt4+1&&cntodd+cnt4==n)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
