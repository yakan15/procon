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
    int res=0;
    int div=10;
    if(n<10){
        cout << n << endl;
        return 0;
    }
    while(n>div){
        res+=9*div/10;
        div*=100;
    }
    res+=max(0,n-div/10+1*(n!=div));
    cout << res << endl;
    return 0;
}
