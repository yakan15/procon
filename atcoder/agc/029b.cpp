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
    ll n;cin>>n;
    map<ll,ll> mp; 
    rep(i,n){
        ll tmp;
        cin>>tmp;
        mp[tmp]++;
    }
    mp[0]++;mp[1000000005]++;
    ll cnt=0;
    for(int i=40;i>=1;i--){
        ll val = 1LL<<i;
        auto it = mp.begin();
        it++;
        while(it!=mp.end()&&(*it).first!=1000000005){
            auto it2 = mp.find(val-(*it).first);
            if(!(it==it2&&(*it).second<2)&&it2!=mp.end()&&(*it2).first!=0&&(*it2).first!=1000000005){
                DEBUG{
                    printf("mp.first: %lld\n",(*it2).first);
                    printf("mp.second: %lld\n",(*it2).second);
                }
                if((*it2).second==1){
                    it2 = mp.erase(it2);
                }else{
                    (*it2).second--;
                }
                if((*it).second==1){
                    it = mp.erase(it);
                }else{
                    (*it).second--;
                }
                cnt++;
            }else{
                it++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
