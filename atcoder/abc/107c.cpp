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
    vector<ll> minus,plus;
    minus.push_back(0);
    plus.push_back(0);
    rep(i,n){
       ll tmp;
       cin >> tmp;
       if(tmp<0)minus.push_back(tmp);
       else plus.push_back(tmp); 
    }
    sort(minus.begin(),minus.end(),greater<ll>());
    ll res = 1LL<<60;
    for(int i=0;i<=k;i++){
        DEBUG{
            cout << res << endl;
        }
        if(i>minus.size()-1||k-i>plus.size()-1)continue;
        res = min(res, plus[k-i]-minus[i]+min(plus[k-i],minus[i]*-1));
    }
    cout << res << endl;
    return 0;
}
