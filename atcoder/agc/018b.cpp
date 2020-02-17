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
    int n,m;cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    vector<bool> checked(m,false);
    rep(i,n){
        rep(j,m){
            cin>>mat[i][j];
            mat[i][j]--;
        }
    }
    vector<int> cur(n,0);
    vector<int> tmp(m,0);
    rep(i,n){
        tmp[mat[i][0]]++;
    }
    int res = 0;
    rep(i,m){
        chmax(res, tmp[i]);
    }
    DEBUG{
        printf("res: %d\n",res);
    }
    rep(i,m-1){
        vector<int> cnt(m,0);
        rep(j,n){
            cnt[mat[j][cur[j]]]++;
        }
        int del,mx=0;
        rep(j,m){
            if(chmax(mx,cnt[j])){
                del = j;
            }
        }
        checked[del]=true;
        chmin(res, mx);
        rep(j,n){
            while(checked[mat[j][cur[j]]]){
                cur[j]++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
