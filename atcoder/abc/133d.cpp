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
    cin >>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll res=0;
    rep(i,n)res+=a[i];
    for(int i=1;i<n-1;i+=2)res-=2*a[i]; 
    cout << res << " ";
    for(int i=1;i<n;i++){
        res = 2*a[i-1]-res;
        cout << res;
        if(i!=n-1)cout << " ";
    }
    cout << endl;
    return 0;
}
