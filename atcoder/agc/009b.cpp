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
    vector<int> a(n,0);
    vector<set<int>> children(n);
    repr(i,1,n){
        cin>>a[i];
        a[i]--;
        children[a[i]].insert(i);
    }

    vector<int> memo(n,-1);
    stack<int> stk;
    stk.push(0);
    while(!stk.empty()){
        DEBUG{
            printf("now: %d\n", stk.top());
            printf("memo: %d\n", memo[stk.top()]);
        }
        int now = stk.top();
        bool flg = true;
        if(children[now].size()==0){
            memo[now]=0;
            stk.pop();
            continue;
        }
        for(auto x:children[now]){
            if(memo[x]==-1){
                flg = false;
                stk.push(x);
            }
        }
        if(flg){
            vector<int> vec;
            for(auto x:children[now]){
                vec.push_back(memo[x]);
            }
            sort(begin(vec),end(vec));
            int depth = 0;
            rep(i,vec.size()){
                depth = max(depth, vec[i])+1;
            }
            memo[now] = depth;
            stk.pop();
        }
    }
    cout << memo[0] << endl;
    return 0;
}
