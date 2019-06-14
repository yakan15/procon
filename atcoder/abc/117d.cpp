#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
vector<ull> cnt(64,0);
ull dp[51][2];
ull num,k;

ull digit_dp(ull n, bool smaller){
    ull res;
    if(n==-1)return 0;
    if(dp[n][smaller]!=-1)return dp[n][smaller];
    if(smaller){
        res=digit_dp(n-1,true)+(max(cnt[n],(num-cnt[n]))<<n);
    }else{
        if(k>>n&1){
            res=digit_dp(n-1,true)+(cnt[n]<<n);
            res=max(res,digit_dp(n-1,false)+(num-cnt[n]<<n));
        }else{
            res=digit_dp(n-1,false)+(cnt[n]<<n);
        }
    }
    // DEBUG{printf("n : %llu, cnt[n] : %llu, smaller : %d, res : %lld\n",n,cnt[n],int(smaller),res);}
    return dp[n][smaller]=res;
}

int main(void) {
    cin >> num >> k;
    rep(i,num){
        ull tmp;
        cin >> tmp;
        rep(j,51)cnt[j]+=(tmp>>j)&1;
    }
    // DEBUG{
    //     rep(i,51)cout << cnt[i] << endl;
    // }
    rep(i,51)rep(j,2)dp[i][j]=-1;
    ull res = digit_dp(50,false);
    cout << res << endl;

    return 0;
}
