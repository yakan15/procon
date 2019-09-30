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
    int n,k;cin>>n>>k;
    vector<int> a(n);rep(i,n){cin>>a.at(i);}
    vector<vector<int> > dp(k+1,vector<int>(2,-1));
    sort(a.begin(),a.end());
    stack<pair<int,int> > stk;
    stk.push(make_pair(0,0));
    while(!stk.empty()){
        int cur = stk.top().first; 
        int num = stk.top().second; 
        DEBUG{
            printf("cur: %d, nu: %d\n",cur,num);
        }
        assert(num==1||num==0);
        assert(0<=cur&&k>=cur);
        int flg=0;
        bool flg2=true;
        for(auto x: a){
            if(cur+x<=k){
                if(dp[cur+x][1-num]!=-1){
                    flg |= 1-dp[cur+x][1-num];
                }else{
                    flg2=false;
                }
            }
        }
        if(flg){
            dp[cur][num]=1;
            stk.pop();
        }else if(flg2){
            dp[cur][num]=0;
            stk.pop();
        }else{
            for(auto x:a){
                if(cur+x<=k&&dp[cur+x][1-num]==-1){
                    stk.push(make_pair(cur+x,1-num));
                }
            }
        }
    }
    cout << (dp[0][0] ? "First" : "Second") << endl;
    return 0;
}
