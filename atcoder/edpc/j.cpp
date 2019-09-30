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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<vector<vector<double> > > dp(301,vector<vector<double> >(301,vector<double>(301,-1)));
    int cnt[4]={};
    dp[0][0][0]=0;
    rep(i,n){
        int tmp;cin>>tmp;
        cnt[tmp]++;
    }
    function<double(int,int,int)> solve = [&](int c3,int c2, int c1){
        if(dp.at(c3).at(c2).at(c1)!=-1){return dp[c3][c2][c1];} 
        double res=0;
        res += (double)n/(c1+c2+c3);
        if(c3!=0){res += solve(c3-1,c2+1,c1)*(double)c3/(c1+c2+c3);}
        if(c2!=0){res += solve(c3,c2-1,c1+1)*(double)c2/(c1+c2+c3);}
        if(c1!=0){res += solve(c3,c2,c1-1)*(double)c1/(c1+c2+c3);}
        return dp[c3][c2][c1] = res;
    };
    printf("%.16f\n",solve(cnt[3],cnt[2],cnt[1]));
    return 0;
}
