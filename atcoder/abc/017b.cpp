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
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    ll diff = abs(b-a);
    // if(n%2==0){
    //     diff = abs(diff-c);
    //     n--;
    // }
    n--;
    bool flg= diff <= d*n && diff >= c*n;
    ll init = n%2; 
    DEBUG{cout << init << endl;}
    for(ll i=init;i<=n;i+=2){
        if(flg){break;}
        flg = diff <= d*i && diff >= c*i ||
        abs(diff-d*i)<=(d-c)*(n-i)/2 ||
        abs(diff-c*i) <= (d-c)*(n-i)/2;
    }
    cout << (flg ? "YES" : "NO") << endl;
    return 0;
}
