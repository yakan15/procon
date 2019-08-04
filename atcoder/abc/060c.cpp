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
    ll n,t;
    cin>>n>>t;
    ll now,prev,res=0;
    cin>>now;
    prev=now;
    rep(i,n-1){
        cin>>now;
        res += min(t,now-prev);
        prev=now;
    }
    res +=t;
    cout<< res<<endl;
    return 0;
}
