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
    ll n;cin>>n;
    string s;cin>>s;
    ll ssize = s.size();
    ll cnt[2]={};
    ll now = 0;
    cnt[0]++;
    ll lr[ssize]={};
    lr[0]=0;
    repr(i,1,ssize){
        if(s.at(i)==s.at(i-1)){
            now = 1- now;
        }
        cnt[now]++;
        lr[i] = now;
    }
    if(s[0]=='W'||s[ssize-1]=='W'||cnt[0]!=cnt[1]){
        cout << 0 << endl;
        return 0;
    }
    ll res=1;
    repr(i,1,n+1){
        res *= i;
        res %= MOD;
    }
    ll cnt2=0;
    for(ll i=ssize-1;i>=0;i--){
        if(lr[i]){
            cnt2++;
        }else{
            res *= cnt2--;
            res %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
