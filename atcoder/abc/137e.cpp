#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
const ll cutoff = 10000000000000000;
int main(void) {
    ll n,m,p;
    cin>>n>>m>>p;
    ll d[n];
    const ll lim = 1LL<<60;
    ll a[m],b[m],c[m];
    bool mat[n][n]={};
    rep(i,n){
        d[i]=lim;
    }
    rep(i,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;c[i]-=p;c[i]*=-1;
        mat[a[i]][b[i]]=true;
    }
    d[0]=0;
    bool closed[n]={};
    queue<int> que;
    DEBUG{
        rep(i,n){
            rep(j,n){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    rep(i,n+1){
        rep(j,m){
            if(d[a[j]]!=lim&&d[b[j]]>d[a[j]]+c[j]){
                d[b[j]] = d[a[j]]+c[j];
                if(i==n){
                    closed[b[j]]=true;
                    que.push(b[j]);
                }
            }
        }
    }
    DEBUG{
        rep(i,n){
            cout << closed[i]<<endl;
        }
    }
    while(!que.empty()){
        int cur = que.front();
        DEBUG{cout <<"front : "<< cur << endl;}

        rep(i,n){
            if(mat[cur][i]&&!closed[i]&&d[cur]<=cutoff){
                DEBUG{cout << i << endl;}
                que.push(i);
                closed[i]=true;
            }
        }
        que.pop();
    } 
    if(closed[n-1]==true){
        cout << -1 << endl;
    }else{
        cout << max(0LL,-d[n-1]) << endl;
    }
    return 0;
}
