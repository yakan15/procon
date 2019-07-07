#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

struct node {
    int x,y,l;
    node(int x, int y, int l) : x(x), y(y), l(l){}
    bool operator>(const node &another) const {
        return l > another.l;
    }
};

int main(void) {
    int  h,w;
    cin >> h >> w;
    int dp[h][w];
    rep(i,h)rep(j,w)dp[i][j]=1<<30;
    dp[0][0]=1;
    string s[h];
    rep(i,h)cin >> s[i];
    int cnt=0;
    rep(i,h)rep(j,w)if(s[i][j]=='.')cnt++;
    priority_queue<node, vector<node>, greater<node> > pq;
    pq.push(node(0,0,1));
    do {
        node now = pq.top();
        pq.pop();
        int x=now.x,y=now.y,l=now.l;
        DEBUG{
            printf("%d %d l : %d",x,y,l);
        }
        if(x>0&&s[x-1][y]=='.'&&(dp[x-1][y]==-1||dp[x-1][y]>l+1)){
            dp[x-1][y]=l+1;
            pq.push(node(x-1,y,l+1));
        }
        if(y>0&&s[x][y-1]=='.'&&(dp[x][y-1]==-1||dp[x][y-1]>l+1)){
            dp[x][y-1]=l+1;
            pq.push(node(x,y-1,l+1));
        }
        if(x<h-1&&s[x+1][y]=='.'&&(dp[x+1][y]==-1||dp[x+1][y]>l+1)){
            dp[x+1][y]=l+1;
            pq.push(node(x+1,y,l+1));
        }
        if(y<w-1&&s[x][y+1]=='.'&&(dp[x][y+1]==-1||dp[x][y+1]>l+1)){
            dp[x][y+1]=l+1;
            pq.push(node(x,y+1,l+1));
        }
    }while(!pq.empty());
    if(dp[h-1][w-1]==(1<<30))cout << -1 << endl;
    else cout << cnt-dp[h-1][w-1] << endl;
    return 0;
}
