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
    string s;
    ll k;
    cin>>s>>k;
    ll n = s.size();
    bool flg = true;
    vector<ll> cnt;
    ll c = 0;
    char prev = s[0];
    rep(i,n){
        if(prev == s[i]){
            c++;
        }else{
            cnt.push_back(c);
            c=1;
            prev = s[i];
        }
    }
    cnt.push_back(c);
    ll res = 0;
    DEBUG{
        cout << cnt.size() << endl;
    }
    repr(i, 1, cnt.size()-1){
        res += cnt[i]/2;
    }
    DEBUG{
        rep(i,cnt.size()){
            cout << cnt[i] << " ";
        }
        cout << endl;
        cout << cnt[cnt.size()-1] << endl;
    }
    if(cnt.size()==1){
        ll r = ll(cnt[0])*k;
        cout << r/2 << endl;
        return 0;
    }
    if(s[0]==s[n-1]){
        res *= k;
        res += ll(cnt[0]+cnt[cnt.size()-1])/2*(k-1);
        res += cnt[0]/2;
        res += cnt[cnt.size()-1]/2;
    }
    else{
        res += cnt[0]/2;
        res += cnt[n-1]/2;
        res *= k;
    }
    cout << res << endl;
    return 0;
}
