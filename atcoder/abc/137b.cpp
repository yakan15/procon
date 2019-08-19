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
    int k,x;
    cin>>k>>x;
    for(int i=-300;i<=300;i++){
        if(abs(i-x)<k){
            cout << i;
            if(i-x==k-1){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
    return 0;
}
