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
    cin >> n;
    int a[n];
    rep(i,n)cin>>a[i];
    int up[n+1]={},down[n+1]={};
    rep(i,n)up[i+1]=max(up[i],a[i]);
    rep(i,n)down[n-i-1]=max(down[n-i],a[n-i-1]);
    rep(i,n){
        cout << max(up[i],down[i+1])<<endl;;
    }
    return 0;
}
