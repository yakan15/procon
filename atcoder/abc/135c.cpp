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
    int n;
    cin >> n;
    ll a[n],b[n];
    rep(i,n+1){cin>>a[i];}
    rep(i,n){cin>>b[i];}
    ll res=0;
    rep(i,n){
        ll tmp = min(a[i],b[i]);
        res += tmp;
        b[i] -= tmp;
        if(b[i]>0){
            tmp = min(a[i+1], b[i]);
            res += tmp;
            a[i+1] -= tmp;
        }
    }
    cout << res << endl;
    return 0;
}
