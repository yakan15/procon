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
    ll cnt[3]={};
    rep(i,s.size()){
        cnt[s.at(i)-'a']++;
    }
    ll a=cnt[0],b=cnt[0];
    rep(i,3){
        a=max(a,cnt[i]);
        b=min(b,cnt[i]);
    }
    cout << (a-b>1 ? "NO" : "YES") << endl;
    return 0;
}
