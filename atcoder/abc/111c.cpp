#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int a[100005]={},b[100005]={};
    int n;
    cin >> n;
    rep(i,n){
        int tmp;
        cin >> tmp;
        if(i%2)b[tmp]++;
        else a[tmp]++;
    }
    int ma=0,mb=0,res=0,ia,ib,ma2,mb2;
    rep(i,100005){
        res+=a[i];
        if(ma<=a[i]){
            ma2=ma;
            ma=a[i];
            ia=i;
        }else if(ma2<=a[i])ma2=a[i];
    }
    rep(i,100005){
       res+=b[i];
        if(mb<=b[i]){
            mb2=mb;
            mb=b[i];
            ib=i;
        }else if(mb2<=b[i])mb2=b[i];
    }
    if(ia==ib)cout << min(res-ma-mb2,res-ma2-mb) << endl;
    else cout << res-ma-mb << endl;
    return 0;
}
