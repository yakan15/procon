#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

double pow4(double x){
    return pow(x,4);
}

double pow2(double x){
    return pow(x,2);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int xy[3][2];
    rep(i,3){
        rep(j,2){cin>>xy[i][j];}
    }
    double r = 0;
    rep(i,3){
        double ax=xy[i][0],ay=xy[i][1],bx=xy[(i+1)%3][0],by=xy[(i+1)%3][1],cx=xy[(i+2)%3][0],cy=xy[(i+2)%3][1];
        double ab = sqrt(pow2(ay-by)+pow2(ax-bx));
        double bc = sqrt(pow2(cy-by)+pow2(cx-bx));
        double ca = sqrt(pow2(cy-ay)+pow2(cx-ax));
        double x = (bc+ca-ab)/2;
        double dx = ax + (cx-ax)*(x/ca);
        double dy = ay + (cy-ay)*(x/ca);
        double bd = sqrt(pow2(dy-by)+pow2(dx-bx));
        double S = sqrt(pow2(pow2(ab)+pow2(x)+pow2(bd))-2*(pow4(ab)+pow4(x)+pow4(bd)))/4;
        r = max(r, 2*S/(x+bd+ab));
    } 
    printf("%.16f\n",r);
    return 0;
}
