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
    ll n;
    cin>>n;
    string s[n];
    rep(i,n){cin>>s[i];}
    ll cnt[26]={};
    ll cnts[26][11]={};
    unordered_map<string, ll> mp;
    rep(i,n){
        rep(j,26){cnt[j]=0;}
        rep(j,10){
            cnt[s[i][j]-'a']++;
        }
        string ss="";
        rep(j,26){
           ss += to_string(cnt[j]);
           ss += ","; 
        }
        DEBUG{cout << ss << endl;}
        mp[ss]++;
    }
    ll res = 0;
    for(auto x:mp){
        res += x.second * (x.second-1) / 2;
    }
    cout << res << endl;
    return 0;
}
