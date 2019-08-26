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
    string s;cin>>s;
    ll cnt[26]={};
    ll n = s.size();
    rep(i,n){
        cnt[s[i]-'a']++;
    }
    ll res = n*(n-1)/2;
    rep(i,26){
        res -= cnt[i]*(cnt[i]-1)/2;
    }
    cout << res+1 << endl;
    return 0;
}
