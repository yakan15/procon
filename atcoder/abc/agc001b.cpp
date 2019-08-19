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
    ll n,x;
    cin>>n>>x;
    ll res = 0;
    res += n;
    ll height = x,width = n-x;
    DEBUG{printf("height : %lld, width : %lld\n", height, width);}
    while(width % height!=0){
        res += height * (width / height) * 2;
        ll tmp = width % height;
        width = height;
        height = tmp;
        DEBUG{printf("height : %lld, width : %lld\n", height, width);}
    }
    res += width * 2 - height;
    cout << res << endl;
    return 0;
}
