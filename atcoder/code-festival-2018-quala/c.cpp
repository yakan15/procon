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
    ll n,k;cin>>n>>k;
    vector<ll> a(n),b(n);rep(i,n){cin>>a[i];}
    for(int i=n;i>0;i--){
        ll tmp = a[i-1];
        ll cnt=0;
        while(tmp>0){
            tmp /=2;
            cnt++;
        }
        b[i-1]=cnt;
    }
    chmin(k, 60*n);
    DEBUG{
        rep(i,n){printf("b %lld ",b[i]);}
        printf("\n");
    }
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(k+10,vector<ll>(2,-1)));
    function<ll(ll, ll, bool)> solve = [&](ll idx, ll remain, bool flg){
        if(dp[idx][remain][flg]!=-1){return dp[idx][remain][flg];}
        ll tmp = b[idx],cnt=0;
        if(idx==n-1){
            DEBUG{
                printf("idx: %lld, remain: %lld, flg:%d\n",idx,remain,flg);
            }
            if(flg){return dp[idx][remain][flg] = (min(b[idx], remain)+1LL)%MOD;}
            return dp[idx][remain][flg] = 1LL;
        }
        ll res=solve(idx+1,remain,flg);
        while(remain-cnt>0&&tmp>1){
            tmp--;
            cnt++;
            res += solve(idx+1,remain-cnt,flg);
            res %= MOD;
        }
        cnt++;
        if(remain-cnt>=0){
            res += solve(idx+1, remain-cnt,true);
            res %= MOD;
        }
        DEBUG{
            printf("idx: %lld, remain: %lld, flg:%d cnt: %lld\n",idx,remain,flg,res);
        }
        return dp[idx][remain][flg] = res % MOD;
    };
    cout << solve(0,k,false) << endl;
    return 0;
}
