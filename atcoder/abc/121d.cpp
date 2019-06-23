#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a,b;
ll dp[65]={};

ll mask(int n){
    ll ret=0;
    rep(i,n){
        ret<<=1;
        ret++;
    }
    return ret;
}

void dfs_b(bool smaller, int n, int m){
    // DEBUG{printf("%d %d %d\n",smaller,n,m);}
    if(n==0)return;
    if(smaller){
        dp[n]+=(1LL<<m-1)%2;
        dfs_b(true, n-1,m);
    }else{
        if(((b>>n-1)&1)==1){
            dp[n]+=((b&mask(n-1))+1)%2;
            dfs_b(false,n-1,0);
            dfs_b(true,n-1,n-1);
        }else{
            dfs_b(false,n-1,0);
        }
    }
    return;
}

void dfs_a(bool smaller, int n, int m){
    if(n==0)return;
    if(smaller){
        dp[n]+=(1LL<<m-1)%2;
        dfs_a(true, n-1,m);
    }else{
        if(((a>>n-1)&1)==1){
            dp[n]+=((a&mask(n-1))+1)%2;
            dfs_a(false,n-1,0);
            dfs_a(true,n-1,n-1);
        }else{
            dfs_a(false,n-1,0);
        }
    }
    return;
}

int main(void) {
    cin >> a >> b;
    a--;
    dfs_b(false,63,0);
    DEBUG{
        cout << dp[3] << dp[2] << dp[1] << endl;
    }
    dfs_a(false,63,0);
    ll res=0;
    DEBUG{
        cout << dp[3] << dp[2] << dp[1] << endl;
    }
    for(int i=63;i>=1;i--){
        res<<=1;
        res += dp[i]%2;
    }
    cout << res << endl;
    return 0;
}
