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
    rep(i,n){cin>>a[i];}
    sort(a,a+n);
    int sum[n];
    sum[0]=0;
    int now=a[0];
    int res=1;
    for(int i=1;i<n;i++){
        if(now==a[i]){
            sum[i]=sum[i-1]+1;
        }else{
            now=a[i];
            sum[i]=sum[i-1];
            res++;
        }
    }
    DEBUG{cout << res << endl;}
    int diff=n+1;
    for(int i=1;i<n;i++){
        diff=min(diff,abs(sum[n-1]-2*sum[i]));
    }
    if(diff%2){res--;}
    cout << res << endl;
    return 0;
}
