#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll n,k;
    cin >> n >> k;
    vector<ll> a;
    vector<ll> sum_a;
    a.push_back(0);
    sum_a.push_back(0);
    ll s=0;
    rep(i,n){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
        s+=tmp;
        sum_a.push_back(s);
    }
    ll res=0;
    rep(i,n+1){
        auto to = lower_bound(sum_a.begin(), sum_a.end(),sum_a[i]+k);
        res += ll(sum_a.end()-to);
    }
    cout << res << endl;
    return 0;
}
