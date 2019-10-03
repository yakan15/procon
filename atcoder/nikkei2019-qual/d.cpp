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
    int n,m;cin>>n>>m;
    set<int> children[n+1];
    vector<int> cnt(n+1,0);
    vector<int> parent(n+1,0);

    rep(i,n+m-1){
        int s,t;cin>>s>>t;
        s;t;
        cnt[t]++;
        children[s].insert(t);
    }
    int root;
    repr(i,1,n+1){
        if(cnt[i]==0){
            root = i;
        }
    }
    stack<int> que;
    que.push(root);
    vector<bool> check(n,false);
    while(!que.empty()){
        int now = que.top();
        que.pop();
        // if(check[now]){
        //     continue;
        // }
        check[now]=true;
        DEBUG{
            printf("now: %d\n",now);
        }
        for(auto x:children[now]){
            cnt[x]--;
            if(cnt[x]==0){
                que.push(x);
            }
            parent[x] = now;
        }
    }
    repr(i,1,n+1){
        cout << parent[i] << endl;
    }
    return 0;
}
