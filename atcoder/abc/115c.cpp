#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,k;
vector<ll> h;

int main(void) {
    cin >> n>> k;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        h.push_back(tmp);
    }
    sort(h.begin(),h.end());
    ll res=ll(1)<<60;
    rep(i,n-k+1){
        res=min(res,h[i+k-1]-h[i]);
    }
    cout << res << endl;
    return 0;
}
