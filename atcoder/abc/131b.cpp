#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,l;
    cin >> n >> l;
    int s=0;
    int res=INT_MAX,diff;
    rep(i,n){
        s+=l+i;
    }
    diff=INT_MAX;
    rep(i,n){
       if(abs(l+i)<diff){
           diff=abs(l+i);
           res=s-(l+i);
       }
    }
    cout << res << endl;
    return 0;
}
