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
    ll a[n];
    rep(i,n){
        cin >> a[i];
        a[i]-=i+1;
    }
    sort(a,a+n);
    ll cur=(n-1)/2;

    ll res=1LL<<60;
    for(int j=-1;j<=1;j++){
        if(cur+j>n||cur+j<0)continue;
        ll sum=0;
        rep(i,n){
            sum+=abs(a[i]-a[cur+j]);
        }
        if(sum<res)res=sum;
    }
    cout << res << endl;
    return 0;
}
