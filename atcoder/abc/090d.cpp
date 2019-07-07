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
    cin >> n >> k;
    ll res=0;
    for(ll i=k+1;i<=n;i++){
        res += (i-k)*(n/i)+(max(0LL,n%i-k+1*ll(k!=0)));
        DEBUG{cout << res << endl;}
    }
    cout << res << endl;
    return 0;
}
