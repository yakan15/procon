#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll n,m;
    cin >> n >> m;
    int max_l=0,min_r=INT_MAX;
    rep(i,m){
        int l,r;
        cin >> l >> r;
        max_l = max(l,max_l);
        min_r = min(r,min_r);
    }
    cout << max(0, min_r-max_l+1) << endl;
    return 0;
}
