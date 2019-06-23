#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll a,b,res=0;
    cin >> a >> b;
    if(a%2==1&&b%2==1){
        res^=a;
        res^=(b-a)/2&1;
    }else if(a%2==0&&b%2==0){
        res^=b;
        res^=(b-a)/2&1;
    }else if(a%2==1&&b%2==0){
        res^=b;
        res^=a;
        res^=((b-a-1)/2)&1;
    }else{
        res^=(b-a+1)/2&1;
    }
    cout << res << endl;


    return 0;
}
