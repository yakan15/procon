#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int a[n],b[n],c[n-1];
    rep(i,n){cin>>a[i];a[i]--;}
    rep(i,n){cin>>b[i];}
    rep(i,n-1){cin>>c[i];}
    int res=0;
    int prev;
    rep(i,n){
        res += b[a[i]];
        if(i!=0&&prev+1==a[i]){res += c[prev];}
        prev = a[i];
    }
    cout << res << endl;
    return 0;
}
