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
    vector<double> v(n);
    double res=0;
    rep(i,n){
        cin>>v.at(i);
    }
    sort(v.begin(),v.end());
    res = v.at(0);
    for(int i=1;i<n;i++){
        res = (res+v.at(i))/2;
    }
    printf("%lf\n",res);
    return 0;
}
