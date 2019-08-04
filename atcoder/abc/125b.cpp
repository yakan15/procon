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
    int n;
    cin>>n;
    int v[n],c[n];
    rep(i,n)cin>>v[i];
    rep(i,n)cin>>c[i];
    int res=0;
    rep(i,n){
        res += max(0,v[i]-c[i]);
    }
    cout << res << endl;
    return 0;
}
