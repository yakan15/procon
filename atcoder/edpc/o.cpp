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
    vector<vector<ll>> dp(n, vector<ll>(1<<n,-1));
    // vector<vector<set<ll> > > candidates(2,vector<set<ll>(n,set<ll>()));
    vector<int> candidates(n,0);
    rep(i,n){
        rep(j,n){
            int tmp;cin>>tmp;
            candidates[i] |= ((tmp<<j));
        }
    }
    function<ll(int,int)> solve = [&](int num, int women){
        if(dp[num][women]!=-1){return dp[num][women];}
        ll res = 0;
        int match = candidates[num] & women;
        DEBUG{
            printf("num: %d, match: %d\n",num,match);
        }
        if(match==0){return dp[num][women] = 0;}
        if(num==n-1&&match!=0){
            return dp[num][women] = 1;
        }
        rep(i,n){
            if(match>>i&1){
                res += solve(num+1,women^(1<<i)); 
                res %= MOD;
            }
        }
        return dp[num][women] = res;
    };
    cout << solve(0,(1<<n)-1) << endl;
    return 0;
}
