#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

struct value{
    int w,v,c;
    value(int w, int v, int c) : w(w), v(v), c(c) {}
    bool operator<(const value &another) const {
        return c < another.c;
    }
};

int main(void) {
    int N,W,C;
    cin>>N>>W>>C;
    vector<vector<vector<vector<int> > > > dp(N+1,vector<vector<vector<int> > >(W+1,vector<vector<int> >(C+1,vector<int>(2,0))));
    vector<value> items(N,value(0,0,0));
    rep(i,N)cin>>items[i].w>>items[i].v>>items[i].c;
    sort(items.begin(),items.end()); 
    rep(i,N){
        bool same_as_prev = (i!=0&&items[i].c==items[i-1].c);
        int nw=items[i].w,nc=items[i].c,nv=items[i].v;
        rep(j,W+1){
            rep(k,C+1){
                if(same_as_prev){
                    dp[i+1][j][k][0]=dp[i][j][k][0];
                    dp[i+1][j][k][1]=dp[i][j][k][1];
                    if(k>0&&j>=nw){
                        dp[i+1][j][k][1]=max(dp[i][j][k][1],max(dp[i][j-nw][k][1],dp[i][j-nw][k-1][0])+nv);
                    }
                }else{
                    dp[i+1][j][k][0]=max(dp[i][j][k][0],dp[i][j][k][1]);
                    if(k>0&&j>=nw){
                        dp[i+1][j][k][1]=max(dp[i][j-nw][k-1][0],dp[i][j-nw][k-1][1])+nv;
                    }
                }
            }
        }
    }
    int res=0;
    rep(i,W+1)rep(j,C+1)rep(k,2){
        res = max(res,dp[N][i][j][k]);
    }
    cout << res << endl;

    return 0;
}
