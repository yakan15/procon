#include <bits/stdc++.h>
#define repr(i,from,to) for(long long (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(long long (i)=0;(i)<(n);(i)++)
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
    ll n;cin>>n;
    ll p[n+2];
    rep(i,n){cin>>p[i+1];}
    multiset<ll> idxes;
    ll idx[n+2];
    repr(i,1,n+1){
        idx[p[i]]=i;
    }

    idxes.insert(n+1); 
    idxes.insert(n+1); 
    idxes.insert(0);
    idxes.insert(0);
    ll res = 0;
    ll tmp;
    for(ll i=n;i>0;i--){
        DEBUG{cout << i << endl;}
        auto cur = idxes.lower_bound(idx[i]);
        DEBUG{cout << "cur: " <<*cur<<endl;}
        res += i*(*next(cur,1)-*cur)*(idx[i]-*prev(cur,1));
        res += i*(*prev(cur,1)-*prev(cur,2))*(*cur-idx[i]);
        idxes.insert(idx[i]);
        DEBUG{cout <<"res: " <<res << endl;}
    }
    cout << res << endl;
    return 0;
}
