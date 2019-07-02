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
    int a[n];
    rep(i,n){
        cin >> a[i];
    }

    cout << ceil((n-1)*1.0/(k-1)) << endl;
    return 0;
}
