#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

ll memo[100005]={};

void mod_pow3(ll m){
    memo[0]=1;
    rep(i,m){
        if(i==0)continue;
        memo[i]=memo[i-1]*3;
        memo[i]%=MOD;
    }
    return ;
}

int main(void) {
    string s;
    cin >> s;
    ll n=s.size();
    ll cnt[3][n+1];
    mod_pow3(100000);
    DEBUG{
        rep(i,4)cout << memo[i] << endl;
    }
    rep(i,3)rep(j,n+1)cnt[i][j]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A')cnt[0][i+1]++;
        else if(s[i]=='C')cnt[1][i+1]++;
        else if(s[i]=='?')cnt[2][i+1]++;
        cnt[0][i+1]+=cnt[0][i];
        cnt[1][i+1]+=cnt[1][i];
        cnt[2][i+1]+=cnt[2][i];
    }
    ll res=0;
    for(int i=1;i<n;i++){
        if(s[i-1]=='B'){
            res+=cnt[0][i-1]*(cnt[1][n]-cnt[1][i])*memo[cnt[2][n]];
            res%=MOD;
            res+=cnt[0][i-1]*(cnt[2][n]-cnt[2][i])*memo[max(cnt[2][n]-1,0LL)];
            res%=MOD;
            res+=cnt[2][i-1]*(cnt[1][n]-cnt[1][i])*memo[max(cnt[2][n]-1,0LL)];
            res%=MOD;
            res+=cnt[2][i-1]*(cnt[2][n]-cnt[2][i])*memo[max(cnt[2][n]-2,0LL)];
            res%=MOD;
        }else if(s[i-1]=='?'){
            res+=cnt[0][i-1]*(cnt[1][n]-cnt[1][i])*memo[max(cnt[2][n]-1,0LL)];
            res%=MOD;
            res+=cnt[0][i-1]*(cnt[2][n]-cnt[2][i])*memo[max(cnt[2][n]-2,0LL)];
            res%=MOD;
            res+=cnt[2][i-1]*(cnt[1][n]-cnt[1][i])*memo[max(cnt[2][n]-2,0LL)];
            res%=MOD;
            res+=cnt[2][i-1]*(cnt[2][n]-cnt[2][i])*memo[max(cnt[2][n]-3,0LL)];
            res%=MOD;
        }
        DEBUG{cout << res << endl;}
    }
    cout << res << endl;
    return 0;
}
