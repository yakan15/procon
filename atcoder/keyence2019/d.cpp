#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;cin>>n>>m;
    vector<ll> a(n),b(m);
    vector<pair<ll,ll>> ab;
    rep(i,n){
        cin>>a[i];
        ab.push_back(make_pair(a[i],0));
    }
    ab.push_back(make_pair(0,0));
    rep(i,m){
        cin>>b[i];
        ab.push_back(make_pair(b[i],1));
    }
    sort(begin(a),end(a),greater<ll>());
    sort(begin(b),end(b),greater<ll>());
    sort(begin(ab),end(ab),greater<pair<ll,ll>>());
    rep(i,n-1){
        if(a[i]==a[i+1]){
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i,m-1){
        if(b[i]==b[i+1]){
            cout << 0 << endl;
            return 0;
        }
    }
    ll cntw=0,cnth=0,cur=0,now=n*m,decided=0;
    ll res = 1;
    while(ab[cur].first!=0){
        if(ab[cur].first==ab[cur].first){
            cntw++;cnth++;
            now--;
            decided++;
            cur+=2;
        }else{
            ab[cur].second ? cnth++ : cntw++;
            cur++; 
        }
        ll tmp = 0;
        while(now>ab[cur].first){
            tmp++;
            now--;
        }
        if(cnth*cntw<decided+tmp){
            DEBUG{
                cout << "no" << endl;
            }
            cout << 0 << endl;
            return 0;
        }
        DEBUG{
            printf("tmp: %lld\n",tmp);
            printf("field: %lld\n",cnth*cntw-decided);

        }
        while(tmp>0){
            res *= cnth*cntw-decided;
            res %= MOD;
            decided++;
            tmp--;
        }
    }
    cout << res << endl;
    return 0;
}
