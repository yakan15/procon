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
    ll r,d,x;
    cin>>r>>d>>x;
    rep(i,10){
        cout << (x=r*x-d) << endl;
    }
    return 0;
}
