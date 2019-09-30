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
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<vector<char>> mat(n,vector<char>(n));
    bool flg[n][n]={};
    rep(i,n)rep(j,n){
        mat[i][j]='.';
    }
    int x = -1000;
    int y = n+2000;
    int cnt=0;
    for(int x=-2000,y=n-1+2000;y>=n-2000;x+=3,y--){
        rep(i,3000){
            if(x+i>=0&&x+i<n&&y-i*2>=0&&y-i*2<n){
                mat[x+i][y-i*2] = 'X';
                cnt++;
            }
        }
    }
    function<bool(int,int)> chk = [&](int i, int j){

        bool flg = (mat[i][j]=='X');
        for(int x=-1;x<=1;x+=2){
            flg |= (i+x>=0&&i+x<n&&mat[i+x][j]=='X');
            flg |= (j+x>=0&&j+x<n&&mat[i][j+x]=='X');
        }
        return flg;
    };
    rep(i,n){
        rep(j,n){
            if(!chk(i,j)){
                mat[i][j]='X';
                cnt++;
            }
        }
    }
    DEBUG{
        cout << cnt << endl;
    }
    rep(i,n){
        rep(j,n){
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}
