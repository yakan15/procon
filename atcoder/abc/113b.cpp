#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,t,a;
    cin >> n >> t >> a;
    int res=0;
    double diff=100000.0;
    rep(i,n){
        double h;
        cin >> h;
        if(abs(a-t+h*0.006)<diff){
            res=i+1;
            diff = abs(a-t+h*0.006);
        }
    }
    cout << res << endl;
    return 0;
}
