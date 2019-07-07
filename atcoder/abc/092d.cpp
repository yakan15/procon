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
    int a,b;
    cin >> a >> b;
    char grid[100][100];
    rep(i,50)rep(j,100){
        grid[i][j]='.';
        grid[i+50][j]='#';
    }
    int cntw=1,cntb=1;
    int cnt=0;
    while(cntb<b){
        grid[(cnt/50)*2][(cnt%50)*2]='#';
        cntb++;
        cnt++;
    }
    cnt=0;
    while(cntw<a){
        grid[99-(cnt/50)*2][cnt%50*2]='.';
        cntw++;
        cnt++;
    }
    printf("100 100\n");
    rep(i,100){
        rep(j,100){
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
