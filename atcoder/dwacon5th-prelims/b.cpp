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
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,n){cin>>a[i];}
    vector<ll> cumsum(n+1,0);
    rep(i,n){
        cumsum[i+1] = cumsum[i]+a[i];
    }
    vector<ll> lst;
    rep(i,n){
        repr(j,i,n){
            lst.push_back(cumsum[j+1]-cumsum[i]);
        }
    }
    ll nn = lst.size();
    vector<ll> count(45,0);
    ll now = 44;
    multiset<ll> st; 
    rep(i,nn){
        st.insert(lst[i]);
    }
    ll res = 0;
    while(now>=0){
        ll cnt=0;
        for(auto x:st){
            if(x&(1LL<<now)){
                cnt++;
            }
        }
        if(cnt>=k){
            res += 1LL<<now;
            auto it = st.begin();
            while(it != st.end()){
                if((*it&(1LL<<now))==0){
                    it = st.erase(it);
                }else{
                    it++;
                }
            }
        }
        now--;
    }
    cout << res << endl;
    return 0;
}
