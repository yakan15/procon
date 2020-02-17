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
    string s;ll k;
    cin>>s>>k;
    ll n = s.size();
    vector<ll> cnts;
    char prev = s[0];
    ll cnt = 0;
    rep(i,n){
        if(prev==s[i]){
            cnt++;
        }else{
            cnts.push_back(cnt);
            cnt = 1;
            prev=s[i];
        }
    }
    cnts.push_back(cnt);
    ll n_cnt = cnts.size();
    if(n_cnt==1){
        cout << (k*cnts[0]/2) << endl;
        return 0;
    }
    ll res = 0;
    repr(i,1,n_cnt-1){
        res += cnts[i]/2;
    }
    if(s[0]==s[n-1]){
        res *= k;
        res += (cnts[0]+cnts[n_cnt-1])/2*(k-1);
        res += cnts[0]/2;
        res += cnts[n_cnt-1]/2;
    }
    else{
        res += cnts[0]/2;
        res += cnts[n_cnt-1]/2;
        res *= k;
    }
    cout << res << endl;
    return 0;
}
