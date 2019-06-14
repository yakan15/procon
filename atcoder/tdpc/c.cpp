#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<int> rate;
int k;
vector<vector<double> > dp;

double calc_rate(int a, int b){
    return 1/(1+pow(10,double(rate[b]-rate[a])/400));
}

double dfs(int round, int n){
    DEBUG{printf("n : %d, round : %d\n",n,round);}
    if(dp[n][round-1]!=-1){
        DEBUG{printf("calculated\n");}
        return dp[n][round-1];
    }
    if(round==1){
        if(n%2==0)return dp[n][0]=calc_rate(n,n+1);
        else return dp[n][0]=calc_rate(n,n-1);
    }
    double res=0;
    int from = n>>round<<round;
    int to = (n>>round<<round)+(1<<round);
    // DEBUG{printf("from : %d, to : %d\n",from,to);}
    double self_win = dfs(round-1,n);
    for(int i=from;i<to;i++){
        DEBUG{printf("i : %d,n : %d\n",i>>round-1&1,n>>round-1&1);}
        if((i>>round-1&1)==(n>>round-1&1)){
            DEBUG{printf("continue\n");}
            continue;
        }
        res += dfs(round-1,i)*calc_rate(n,i);
    }
    DEBUG{printf("exit\n");}
    return dp[n][round-1] = self_win*res;
}

int main(void) {
    cin >> k;
    rep(i,(1<<k)){
        int tmp;
        cin >> tmp;
        rate.push_back(tmp);
    }
    dp = vector<vector<double> >(1<<k,vector<double>(k,-1));
    rep(i,(1<<k)){
        cout << fixed << setprecision(10) << dfs(k,i) << endl;
    } 

    return 0;
}
