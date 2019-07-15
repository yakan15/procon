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
    int w[n];
    rep(i,n)cin>>w[i];
    int sum[n]={};
    rep(i,n){
        sum[i]+=w[i];
        if(i>0)sum[i]+=sum[i-1];
    }
    int res=1<<30;
    for(int i=0;i<n;i++){
        res=min(res, abs(sum[n-1]-sum[i]*2));
    }
    cout << res << endl;
    return 0;
}
