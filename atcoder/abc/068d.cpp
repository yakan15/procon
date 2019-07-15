#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n;
    cin>>n;
    int edge[n][2];
    rep(i,n-1)cin>>edge[i][0]>>edge[i][1];
    set<int> neighbors[n+1];
    rep(i,n-1){
        neighbors[edge[i][0]].insert(edge[i][1]);
        neighbors[edge[i][1]].insert(edge[i][0]);
    }
    queue<int> que;
    int d_a[n+1],d_b[n+1];
    int checked[n+1]={};
    checked[1]=true;
    d_a[1]=0;d_b[n]=0;
    que.push(1);
    while(!que.empty()){
        int tmp=que.front();
        que.pop();
        for(auto x:neighbors[tmp]){
            if(!checked[x]){
                checked[x]=true;
                que.push(x);
                d_a[x]=d_a[tmp]+1;
            }
        }
    }
    que.push(n);
    rep(i,n+1)checked[i]=false;
    checked[n]=true;
    while(!que.empty()){
        int tmp=que.front();
        que.pop();
        for(auto x:neighbors[tmp]){
            if(!checked[x]){
                DEBUG{cout << x << endl;}
                checked[x]=true;
                que.push(x);
                d_b[x]=d_b[tmp]+1;
            }
        }
    }
    int cnt=0;
    rep(i,n){
       if(d_a[i+1]<=d_b[i+1])cnt++; 
    }
    DEBUG{cout << cnt << endl;}
    if(cnt*2>n)cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
