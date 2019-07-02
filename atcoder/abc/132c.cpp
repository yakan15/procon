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
    cin >> n;
    ll d[n];
    rep(i,n)cin >> d[i];
    sort(d, d+n);
    ll sum[100005];
    ll cur=0;
    rep(i,100005){
        // DEBUG{cout << i << endl;}
        while(d[cur]<i&&cur<n)cur++;
        sum[i]=cur;
    }
    ll res=0;
    rep(i,100005){
        if(sum[i]==sum[100004]-sum[i])res++;
    }
    cout << res << endl;
    return 0;
}
