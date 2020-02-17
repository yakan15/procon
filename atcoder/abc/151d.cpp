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
    int h,w;
    cin>>h>>w;
    vector<string> road(h);
    rep(i,h) {
        cin >> road[i];
    }
    int res = 0;
    function<int(int,int)> solve =[&] (int sh, int sw) {
        vector<vector<int>> mp(h,vector<int>(w,50000));
        mp[sh][sw] = 0;
        int mx = 0;
        queue<pair<int,int>> que;
        que.emplace(sh,sw);
        while(!que.empty()) {
            auto now = que.front();
            que.pop();
            int hh = now.first;
            int ww = now.second;
            chmax(mx, mp[hh][ww]);
            if (hh > 0 && road[hh-1][ww] == '.' && mp[hh][ww] + 1 < mp[hh-1][ww]) {
                mp[hh-1][ww] = mp[hh][ww] + 1;
                que.emplace(hh-1,ww);
            }
            if (hh < h-1 && road[hh+1][ww] == '.' && mp[hh][ww] + 1 < mp[hh+1][ww]) {
                mp[hh+1][ww] = mp[hh][ww] + 1;
                que.emplace(hh+1,ww);
            }
            if (ww > 0 && road[hh][ww-1] == '.' && mp[hh][ww] + 1 < mp[hh][ww-1]) {
                mp[hh][ww-1] = mp[hh][ww] + 1;
                que.emplace(hh,ww-1);
            }
            if (ww < w-1 && road[hh][ww+1] == '.' && mp[hh][ww] + 1 < mp[hh][ww+1]) {
                mp[hh][ww+1] = mp[hh][ww] + 1;
                que.emplace(hh,ww+1);
            }
        }
        return mx;
    };
    rep(i,h) {
        rep(j,w) {
            if(road[i][j] != '.')continue;
            chmax(res, solve(i,j));
        }
    }
    cout << res << endl;
    return 0;
}
