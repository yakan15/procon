#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int a;
    cin >> a;
    int tst=a%10;
    rep(i,3){
        a/=10;
        if(tst==a%10){cout << "Bad" << endl;return 0;}
        else tst=a%10;
    }
    cout << "Good" << endl;
    return 0;
}
