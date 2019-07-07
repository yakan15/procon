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
    int a[n],b[n];
    int ma[n],mb[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    int res=0;
    rep(i,29){
        int cnt=0;
        int mod = 1<<i+1;
        DEBUG{cout << "mod " << mod << endl;}
        rep(j,n){
            ma[j]=a[j]%mod;
            mb[j]=b[j]%mod;
        }
        sort(ma,ma+n);
        sort(mb,mb+n);
        rep(j,n){
            rep(k,2){
                auto from = lower_bound(mb,mb+n,mod/2*(2*k+1)-ma[j]);
                auto to = lower_bound(mb,mb+n,mod/2*(2*k+2)-ma[j]);
                cnt+= int(to-from);
            }
        }
            DEBUG{cout << "cnt " << cnt << endl;}
            res+=(1<<i)*(cnt&1);
    }
    cout << res << endl;
    return 0;
}
