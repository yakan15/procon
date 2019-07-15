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
    int h,w,n;
    cin>>h>>w>>n;
    int color[h][w];
    int a[n];
    rep(i,n)cin>>a[i];
    int x=0,y=0;
    rep(i,n){
        rep(j,a[i]){
            color[y][x]=i+1;
            if(y%2){
                if(x==0)y++;
                else x--;
            }else{
                if(x==w-1){
                    y++;
                }else x++;
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << color[i][j];
            if(j!=w-1)cout << " ";
        }
        cout<<endl;
    }
    return 0;
}
