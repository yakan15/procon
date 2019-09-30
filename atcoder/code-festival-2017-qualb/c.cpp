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
    ll n,m;cin>>n>>m;
    vector<set<int>> neighbors(n);
    rep(i,m){
        int a,b;cin>>a>>b;
        a--;b--;
        neighbors[a].insert(b);
        neighbors[b].insert(a);
    }
    vector<int> color(n,-1);
    function<bool()> is_bipartite = [&](){
        queue<int> que;
        que.push(0);
        color[0]=0;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(auto x:neighbors[cur]){
                if(color[x]==-1){
                    color[x]=1-color[cur];
                    que.push(x);
                }
                else if(color[x]==color[cur]){return false;}
            }
        }
        return true;
    };
    if(is_bipartite()){
        ll cnt=0;
        rep(i,n){
            cnt += color[i];
        }
        cout << (cnt*(n-cnt)-m) << endl;
    }else{
        cout << n*(n-1)/2-m << endl;
    }

    return 0;
}
