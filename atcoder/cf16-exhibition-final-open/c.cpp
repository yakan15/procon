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
    int res=0;
    int a[n];
    rep(i,n){
        cin>>a[i];
        res ^= a[i];
        a[i] = a[i] & (-a[i]);
    }
    sort(a,a+n,greater<int>());
    int cnt=0;
    rep(i,n){
        if(res&a[i]){
            res ^= a[i];
            res ^= a[i]-1;
            cnt++;
        }
    }
    cout << (res==0 ? cnt : -1) << endl;
    return 0;
}
