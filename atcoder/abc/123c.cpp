#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,a[5]={};
int main(void) {
    cin >> n>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    ll min_a=a[0];
    ll min_n=0;
    rep(i,5){
        if(min_a>a[i]){
            min_a=a[i];
            min_n=i;
        }
    }
    cout << n/min_a+4+ll(n%min_a!=0) << endl;

    return 0;
}
