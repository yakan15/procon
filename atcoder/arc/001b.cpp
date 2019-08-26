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
    int a,b;cin>>a>>b;
    int div=abs(a-b)/10,res=abs(a-b)%10;
    cout << (div + min(min(res, abs(res-5)+1),abs(res-10)+1)) << endl;
    return 0;
}
