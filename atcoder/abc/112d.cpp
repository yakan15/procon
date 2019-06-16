#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,m;
    cin >> n >> m;
    int a = m/n;
    while(a>1){
        DEBUG{cout << (m-(a*(m/a)))%a << endl;}
        if((m-(a*(m/a)))%a==0)break;
        a--;
    }
    cout << a << endl;
    return 0;
}
