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
    ll n;cin>>n;
    ll a[n];
    ll diff[n];
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%(n*(n+1)/2)!=0LL){
        DEBUG{printf("out1\n");}
        cout << "NO" << endl;
        return 0;
    }
    ll val = sum/(n*(n+1)/2);
    DEBUG{cout << "val : "<< val << endl;}
    rep(i,n){
        diff[i] = a[(i+1)%n] - a[i] - val;
    }
    ll cnt=0;
    rep(i,n){
        if(diff[i]>0||diff[i]%n){
            DEBUG{printf("out2 i : %d reminder : %lld\n",i,diff[i]%n);}
            cout << "NO" << endl;
            return 0;
        }
        // cnt += -diff[i]/n;
    }
    cout << "YES" << endl;
    return 0;
}
