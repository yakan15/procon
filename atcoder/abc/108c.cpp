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
    ll res = pow(n/k,3);
    if(k%2==0){
        ll tmp=k/2;
        int cnt=0;
        while(tmp<=n){
           cnt++;
           tmp+=k;
        } 
        res += pow(cnt,3); 
    }
    cout << res << endl;
    return 0;
}
