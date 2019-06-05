#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,y;
    cin >> n >> y;
    int res;
    rep(i,n+1){
        rep(j,n+1-i){
            res=i*10000+j*5000+(n-i-j)*1000;
            if(res==y){
                printf("%d %d %d\n",i,j,n-i-j);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}