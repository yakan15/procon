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
    vector<ll> t(n+2,0), a(n+2,0);
    rep(i,n){cin>>t.at(i+1);}
    rep(i,n){cin>>a.at(i+1);}
    t.at(n+1) = t.at(n);
    a.at(0) = a.at(1);
    ll res = 1;
    ll max_now = 0;
    ll cur_from = 1;
    while(cur_from<=n+1&&t[cur_from]!=a[cur_from]){
        if(t.at(cur_from-1)<t.at(cur_from)){
            max_now = t.at(cur_from);
        }else{
            res *= max_now;
            res %= MOD;
        }
        DEBUG{
            cout << res << endl;
        }
        cur_from++;
    }
    ll cur_to = n;
    max_now = 0;
    while(cur_to>=0&&t[cur_to]!=a[cur_to]){
        if(a.at(cur_to)>a.at(cur_to+1)){
            max_now = a.at(cur_to);
        }else{
            res *= max_now;
            res %= MOD;
        }
        DEBUG{
            cout << res << " max : " << max_now << endl;
        }
        cur_to--;
    }
    if(cur_from>=n+1||cur_to<=0||t.at(n)!=a.at(1)||t.at(cur_from)!=t.at(n)||a.at(1)!=a.at(cur_to)){
        cout << 0 << endl;
        return 0;
    }
    for(int i=cur_from+1;i<cur_to;i++){
        res *= t.at(i);
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
