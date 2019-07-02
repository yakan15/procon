#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

ll memo[18];

void pre(){
    ll a=1;
    rep(i,18){
        memo[i]=a;
        a*=10;
    }
}

int main(void) {
    ll k;
    cin >> k;
    ll cnt=0;
    ll base=0;
    pre();
    while(cnt<k){
        if(cnt!=0&&cnt%9==0){
            base*=10;
            base+=9;
        }
        cout << base+(cnt%9+1)*memo[(cnt/9)] << endl;
        cnt++;
    }
    return 0;
}
