#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ull x,y;
    cin >> x >> y;
    ull a=x;
    ull count=1;
    for(;(a*2)<=y;count++){
        a *=2;
    }
    cout << count << endl;
    return 0;
}