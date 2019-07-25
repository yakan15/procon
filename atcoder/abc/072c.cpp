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
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    int res=0;
    rep(i,100000){
        auto from=lower_bound(a,a+n,i);
        auto to=upper_bound(a,a+n,i+2);
        res=max(res,int(to-from));
    }
    cout << res<< endl;
    return 0;
}
