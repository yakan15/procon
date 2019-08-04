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
    int cnt=0;
    rep(i,n){
        if(i+1!=a[i]){
            cnt++;
        }
    }
    if(cnt<=2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
