#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
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


struct point {
    ll x;
    ll y;
    point(ll _x, ll _y): x(_x), y(_y) {}
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w;cin>>h>>w;
    vector<string> a(h);
    vector<vector<ll>> dist(h,vector<ll>(w,100000000));
    queue<point> que;
    rep(i,h) {
        cin>>a[i];
    }
    rep(i,h) {
        rep(j,w) {
            if (a[i][j]=='#') {
                dist[i][j] = 0;
                for(ll x=-1;x<=1;x+=2) {
                    if (i+x>=0 && i+x<h && a[i+x][j]=='.' && dist[i+x][j] > 1) {
                        dist[i+x][j] = 1;
                        que.emplace(i+x,j);
                    }
                    if (j+x>=0 && j+x<w && a[i][j+x]=='.' && dist[i][j+x] > 1) {
                        dist[i][j+x] = 1;
                        que.emplace(i,j+x);
                    }
                } 
            }
        }
    }
    ll res = 0;
    while(!que.empty()) {
        auto now = que.front();
        que.pop();
        chmax(res, dist[now.x][now.y]);
        ll d = dist[now.x][now.y];
        for(ll x=-1;x<=1;x+=2) {
            if (now.x+x>=0 && now.x+x<h && a[now.x+x][now.y]=='.' && dist[now.x+x][now.y] > d+1) {
                dist[now.x+x][now.y] = d+1;
                que.emplace(now.x+x,now.y);
            }
            if (now.y+x>=0 && now.y+x<w && a[now.x][now.y+x]=='.' && dist[now.x][now.y+x] > d+1) {
                dist[now.x][now.y+x] = d+1;
                que.emplace(now.x,now.y+x);
            }
        } 
    }
    cout << res << endl;
    return 0;
}
