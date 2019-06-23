#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> b;
    ll abs_min=1LL<<60;
    int cnt=0;
    ll res=0;
    rep(i,n){
        ll t;
        cin >>t;
        res += abs(t);
        if(t<0)cnt++;
        if(abs(t)<abs_min)abs_min=abs(t);
        b.push_back(t);
    }
    if(cnt%2==0)cout << res << endl;
    else cout << res-2*abs_min << endl;
    return 0;
}
