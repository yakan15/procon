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
    int n;cin>>n;
    vector<string> s(n);rep(i,n){cin>>s[i];}
    ll lim = 1e+10;
    vector<vector<ll>> mat(n,vector<ll>(n,lim));
    rep(i,n){
        mat[i][i] = 0;
        rep(j,n){
            if(s[i][j]=='1'){
                mat[i][j]=1;
            }
        }
    }
    ll d = -1;
    ll start = -1;
    rep(k,n){
        rep(i,n){
            rep(j,n){
                chmin(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(chmax(d,mat[i][j])){
                start = j;
            }
        }
    }
    DEBUG{
        printf("d: %lld\n",d);
        printf("start: %lld\n",start);
    }
    queue<pair<ll,ll>> que;
    que.emplace(start, 1);
    ll res = 1;
    vector<ll> v(n,0);
    v[start] = 1;
    while(!que.empty()){
        auto tmp = que.front();
        DEBUG{
            cout << tmp.first << endl;
        }
        que.pop();
        ll cur = tmp.first;
        chmax(res, tmp.second);
        rep(j,n){
            if(s[cur][j]=='1'){
                if(v[j]==0){
                    v[j]=tmp.second+1;
                    que.emplace(j, v[j]);
                }else if(v[j]!=tmp.second+1&&v[j]!=tmp.second-1){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << d+1 << endl;
    return 0;
}
