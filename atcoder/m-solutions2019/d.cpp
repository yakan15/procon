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
    ll n;cin>>n;
    vector<ll> a(n),b(n),c(n);
    vector<set<ll>> nbs(n,set<ll>());
    rep(i,n-1){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        nbs[a[i]].insert(b[i]);
        nbs[b[i]].insert(a[i]);
    }
    ll vals[n]={};
    ll res=0;
    rep(i,n){
        cin>>c[i];
    }
    sort(begin(c),end(c),greater<ll>());
    repr(i,1,n){
        res += c[i];
    }
    cout << res << endl; 
    queue<ll> que;
    que.push(0);
    bool chk[n]={};
    ll cnt=0;
    while(!que.empty()){
        ll tmp = que.front();
        que.pop();
        vals[tmp]=c[cnt];
        chk[tmp]=true;
        for(auto x:nbs[tmp]){
            if(!chk[x]){
                que.push(x);
            }
        }
        cnt++;
    }
    rep(i,n){
        cout << vals[i] << endl;
    }
    return 0;
}
