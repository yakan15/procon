#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
// http://www.tensyo.com/urame/prog/linealgo.htm
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<long double> x(n),y(n); 
    rep(i,n) {
        cin>>x[i]>>y[i];
    }
    long double res = 1e+10;
    long double eps = 1e-10;
    if (n==2) {
        printf("%.10Lf\n", sqrt((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]))/2);
        return 0;
    }
    rep(i,n) {
        repr(j,i+1,n) {
            repr(k,j+1,n) {
                long double x1=x[i],x2=x[j],x3=x[k],y1=y[i],y2=y[j],y3=y[k];
                // long double g = y2*x1-y1*x2 +y3*x2-y2*x3 +y1*x3-y3*x1;
                long double Xd,Yd,r;
                long double G, Xc,Yc;
                G=( y2*x1-y1*x2 +y3*x2-y2*x3 +y1*x3-y3*x1 );
                Xc= ((x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2))/(2*G);
                Yc=-((x1*x1+y1*y1)*(x2-x3)+(x2*x2+y2*y2)*(x3-x1)+(x3*x3+y3*y3)*(x1-x2))/(2*G);
                // xc = (x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2)/(2*g);
                // yc = -(x1*x1+y1*y1)*(x2-x3)+(x2*x2+y2*y2)*(x3-x1)+(x3*x3+y3*y3)*(x1-x2)/(2*g);
                // r = sqrt((x1-xc)*(x1-xc)+(y1-yc)*(y1-yc));
                // Xd=(((x1*x1+y1*y1)-(x2*x2+y2*y2))*(y2-y3)-((x2*x2+y2*y2)-(x3*x3+y3*y3))*(y1-y2))/(2*((x1-x2)*(y2-y3)-(x2-x3)*(y1-y2)));
                // Yd=(((y1*y1+x1*x1)-(y2*y2+x2*x2))*(x2-x3)-((y2*y2+x2*x2)-(y3*y3+x3*x3))*(x1-x2))/(2*((y1-y2)*(x2-x3)-(y2-y3)*(x1-x2)));
                r=sqrt( (x1 - Xc) * (x1 - Xc) + (y1 - Yc) * (y1 - Yc) );
                bool flg = true;
                rep(l,n) {
                    if (l==i||l==j||l==k) {
                        continue;
                    }
                    if (sqrt((x[l]-Xc)*(x[l]-Xc)+(y[l]-Yc)*(y[l]-Yc))>r+eps) {
                        flg = false;
                    } 
                }
                if(!flg)continue;
                // printf("r:%.10Lf, xc:%.10Lf, yc:%.10Lf",r, Xc,Yc);
                chmin(res, r);
            }
        }
    }
    printf("%.10Lf\n",res);
    return 0;
}
