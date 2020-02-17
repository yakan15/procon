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
    ll h,w;cin>>h>>w;
    vector<string> s(h);
    rep(i,h){
        cin>>s[i];
    }
    vector<vector<bool>> chk(h,vector<bool>(w,false));
    function<ll(ll,ll)> check = [&](ll x, ll y){
        map<char,ll> mp;
        mp[s[x][y]]++;
        queue<pair<ll,ll>> que;
        que.push(make_pair(x,y));
        while(!que.empty()){
            ll xx = que.front().first,yy = que.front().second;
            que.pop();
            for(ll i=-1;i<=1;i+=2){
                if(xx+i>=0&&xx+i<h&&s[xx][yy]!=s[xx+i][yy]&&!chk[xx+i][yy]) {
                    que.push(make_pair(xx+i,yy));
                    chk[xx+i][yy]=true;
                    mp[s[xx+i][yy]]++;
                }
                if(yy+i>=0&&yy+i<w&&s[xx][yy]!=s[xx][yy+i]&&!chk[xx][yy+i]) {
                    que.push(make_pair(xx,yy+i));
                    chk[xx][yy+i]=true;
                    mp[s[xx][yy+i]]++;
                }
            }
        }
        return mp['.']*mp['#'];
    };
    ll res = 0;
    rep(i,h){
        rep(j,w){
            if(!chk[i][j]){
                chk[i][j]=true;
                res += check(i,j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
