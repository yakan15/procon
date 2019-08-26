#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k;cin>>k;
    ll a[k];
    rep(i,k){cin>>a[k-1-i];}
    ll _min[k+1]={},_max[k+1]={};
    _min[0]=_max[0]=2;
    rep(i,k){
        _min[i+1] = ((_min[i]-1LL)/a[i]+1LL)*a[i];
        _max[i+1] = (_max[i]/a[i]+1LL)*a[i]-1LL;
        if(_min[i+1]>_max[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    printf("%lld %lld\n",_min[k], _max[k]);
    return 0;
}
