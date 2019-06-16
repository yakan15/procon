#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll W,H,x,y;
int main(void) {
    cin >> W >> H >> x >> y;
    // if(W%2==1&&H%2==1){
    //     cout << W*H/2 << ".5" << " ";
    // }
    // else cout << W*H/2 << " ";
    double res = double((int(W)))*double(int(H))/2;
    DEBUG{printf("%lf\n", double((int(W)))*double(int(H))/2);}

    cout <<res << " ";
    if(abs(W-x*2)==0&&abs(H-y*2)==0)cout << "1" << endl;
    else cout << "0" << endl;
    
    return 0;
}
