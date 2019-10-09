#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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
template<class T> inline void printb(T a) {
    if(a==0){
        cout << 0 << endl;
        return;
    }
    int cnt = sizeof(T)*8-1;
    bool flg = false;
    while(cnt>=0){
        if(!flg&&a>>cnt&1){
            flg = true;
        }
        if(flg){
            cout << (a>>cnt&1);
        }
        cnt--;
    }
    cout << "\n";
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x,y,z;cin>>n>>x>>y>>z;
    int mask = (1<<x+y+z)-1;
    vector<vector<ll> > dp(n+1,vector<ll>(mask+5,0));
    rep(i,10){
        dp[0][1<<i]=1;
    }
    int checkbit = (1<<z-1) + (1<<z+y-1) + (1<<x+y+z-1); 
    DEBUG{
        printf("checkbit: ");
        printb(checkbit);
        printf("mask: ");
        printb(mask);
    }
    rep(i,n-1){
        rep(j,mask+1){
            rep(k,10){
                int tmp = j;
                tmp<<=1;tmp++;
                tmp<<=k;
                tmp&=mask;
                if((tmp&checkbit) != checkbit){
                    dp[i+1][tmp] += dp[i][j];
                    dp[i+1][tmp] %= MOD;
                }
            }
        }
    }
    ll res = 1;
    rep(i,n){
        res *= 10;
        res %= MOD;
    }
    DEBUG{
        printf("res %lld\n",res);
    }
    rep(i,mask+1){
        res += (MOD-dp[n-1][i]);
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}
