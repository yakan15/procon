#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n;
    cin >> n;
    int t,x,y,now=0,nx=0,ny=0;
    int d,dt;
    rep(i,n){
        cin >> t >> x >> y;
        d = abs(nx-x)+abs(ny-y);
        dt = t-now;
        if(!(d<=dt&&(dt-d)%2==0)){
            cout << "No" << endl;
            return 0;
        }
        nx=x;ny=y;now=t;
    }
    cout << "Yes" << endl;

    return 0;
}