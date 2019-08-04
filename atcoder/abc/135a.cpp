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
    ll a,b;
    cin>>a>>b;
    if((a+b)%2){cout << "IMPOSSIBLE" << endl;}
    else{cout << (a+b)/2 << endl;}
    return 0;
}
