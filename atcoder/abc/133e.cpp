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
    ll n,k;
    cin >> n>> k;
    bool checked[n];
    set<ll> neighbor[n];
    queue<ll> que;
    rep(i,n-1){
        ll tmpa,tmpb;
        cin >> tmpa >> tmpb;
        tmpa--;
        tmpb--;
        neighbor[tmpa].insert(tmpb);
        neighbor[tmpb].insert(tmpa);
    }
    for(auto x:neighbor[0]){
        que.push(x);
        checked[x]=true;
        neighbor[x].erase(0);
    }
    ll res=0;
    res+=k;
    rep(i,que.size()){
        res *= k-1-i;
        res %= MOD;
    }
    // checked[0]=true;
    while(!que.empty()){
        ll cur=que.front();
        que.pop();
        DEBUG{
            cout << "cur "<<cur << endl;
        }
        rep(i,neighbor[cur].size()){
            res *= k-2-i;
            res %=MOD;
        }
        for(auto x:neighbor[cur]){
            // if(!checked[x]){
                que.push(x);
                neighbor[x].erase(cur);
                // checked[x]=true;
            // }
        }
    }
    cout << res << endl;
    return 0;
}
