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
    int l,r;
    int mod=2019;
    cin >> l>>r;
    int x=l%mod,y=r%mod;
    if(x==0||y==0||l+mod<=r)cout << 0 << endl;
    else if(y<=x)cout << 0 << endl;
    else{
        vector<vector<int>> lst(2020,vector<int>(2020,100000));
        rep(i,2020)for(int j=i+1;j<2020;j++){
            if(i<x||y<j)lst[i][j]=100000;
            else lst[i][j]=(i*j)%mod;
        }
        int res=100000;
        rep(i,2020)rep(j,2020){
            if(res > lst[i][j]){
                DEBUG{
                    cout << i << "j " << j << endl;
                }
            }
            res = min(res,lst[i][j]);
        }
        cout << res <<endl;
    }
    return 0;
}
