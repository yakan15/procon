#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void){
    int N;
    cin >> N;
    int a,tmp1,tmp2;
    int count=0;
    a=N;
    int res=1<<30,sum,vala,valb;
    rep(i,N+1){
        sum=0; 
        vala=i;valb=N-i;
        int aa=1;
        while(vala>=aa*6)aa*=6;
        while(vala>0){
            sum+=vala/aa;
            vala=vala%aa;
            aa/=6;
        }
        int bb=1;
        while(valb>=bb*9)bb*=9;
        while(valb>0){
            sum+=valb/bb;
            valb=valb%bb;
            bb/=9;
        }
        if(res>sum){
            res=sum;
            DEBUG{cout << i << endl;}
        }
    }
    cout << res <<endl;
}