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
    int n,q;cin>>n>>q;
    vector<int> a(n),b(n);
    vector<int> parent(n,0);
    vector<vector<int> >  children(n,vector<int>());
    vector<int> res(n,0);
    rep(i,n-1){
        cin>>a.at(i)>>b.at(i);
        a.at(i)--;
        b.at(i)--;
        children.at(a.at(i)).push_back(b.at(i));
        parent.at(b.at(i))=a.at(i);
    }
    rep(i,q){
        int tmp,x;
        cin>>tmp>>x;
        res.at(tmp-1)+=x;
    }
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        if(cur!=0){
            res.at(cur) += res.at(parent.at(cur));
        } 
        for(auto x:children.at(cur)){
            que.push(x);
        }
    }
    rep(i,n){
        cout << res.at(i);
        cout << (i==n-1 ? "\n" : " ");
    }
    return 0;
}
