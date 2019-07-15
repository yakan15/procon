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
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    vector<int> water;
    for(int i=0;a*i<=f/100;i++){
        for(int j=0;a*i+b*j<=f/100;j++)water.push_back(a*i*100+b*j*100);
    }
    int res_ws=0, res_s=0;
    double res_a=0;
    rep(i,water.size()){
        int sugar_max = water[i]/100*e;
        int sugar_amo=0;
        for(int j=0;c*j<=sugar_max&&water[i]+c*j<=f;j++){
            for(int k=0;c*j+d*k<=sugar_max&&water[i]+c*j+d*k<=f;k++)sugar_amo=max(sugar_amo,c*j+d*k);
        }
        if(res_a<=(sugar_amo*100.0)/(sugar_amo+water[i])){
            res_a =(sugar_amo*100.0)/(sugar_amo+water[i]);
            res_ws=sugar_amo+water[i];
            res_s=sugar_amo;
        }
    }
    cout << res_ws << " " << res_s << endl;
    return 0;
}
