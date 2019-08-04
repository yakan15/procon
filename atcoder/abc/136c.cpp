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
    int h[n+1];
    h[0]=0;
    rep(i,n){
        cin>>h[i+1];
    }
    for(int i=1;i<n;i++){
        if(h[i-1]<h[i]){
            h[i]--;
        }
        if(h[i]>h[i+1]){
            cout << "No" <<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
