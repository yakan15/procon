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
    bool flg[10001]={};
    flg[0]=true;
    rep(i,n){
        int tmp;cin>>tmp;
        for(int j=10000;j-tmp>=0;j--){
            flg[j]|=flg[j-tmp];
        }
    }
    for(int i=10000;i>=0;i--){
        if(flg[i]&&i%10!=0){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
