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
    ll res = 0;
    for(ll i=1;i*i<=n;i++){
        if((n-i)%i==0&&(n-i)/i>i){
            res += (n-i)/i;
        }
    }
    cout << res << endl;
    return 0;
}
