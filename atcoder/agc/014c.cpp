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
    int h,w,k;cin>>h>>w>>k;
    int h0,w0;
    vector<string> s(h);
    rep(i,h){cin>>s[i];}
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='S'){
                h0=i;
                w0=j;
            }
        }
    }
    queue<pair<int,int>> que;
    vector<vector<bool>> check(h,vector<bool>(w,false));
    int d = h0;
    chmin(d, w0);
    chmin(d, w-1-w0);
    chmin(d,h-1-h0);
    que.emplace(h0,w0);
    while(!que.empty()){
        auto now = que.front();
        int x = now.first,y=now.second;
        DEBUG{
            cout << x << " " << y << " " << endl;
        }
        que.pop();
        for(int i=-1;i<=1;i+=2){
            if(x+i>=0&&x+i<h&&s[x+i][y]=='.'
                &&!check[x+i][y]&&abs(h0-x-i)+abs(w0-y)<=k){
                check[x+i][y]=true;
                que.emplace(x+i,y);
                chmin(d,x+i);
                chmin(d,y);
                chmin(d,h-1-x-i);
                chmin(d,w-1-y);
            }
            if(y+i>=0&&y+i<w&&s[x][y+i]=='.'
                &&!check[x][y+i]&&abs(h0-x)+abs(w0-y-i)<=k){
                check[x][y+i]=true;
                que.emplace(x,y+i);
                chmin(d,x);
                chmin(d,y+i);
                chmin(d,h-1-x);
                chmin(d,w-1-y-i);
            }
        }
    }
    if(d==0){
        cout << 1 << endl;
        return 0;
    }
    ll res = 1;
    res += (d-1)/k+1;
    cout << res << endl;
    return 0;
}
