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
    int n;
    cin>>n;
    ll a[3*n];
    ll back[2*n];
    map<ll,ll> backmp,backsum;
    priority_queue<ll, vector<ll>, greater<ll> > que;
    priority_queue<ll> que2;
    ll vala[n+1]={},valb[n+1]={};
    rep(i,3*n)cin>>a[i];
    ll tmp=0;
    rep(i,n){
        que.push(a[i]);
        tmp+=a[i];
    }
    vala[0]=tmp;
    tmp=0;
    for(int i=2*n;i<3*n;i++){
        que2.push(a[i]);
        tmp+=a[i];
    }
    valb[0]=tmp;
    for(int i=0;i<n;i++){
        que.push(a[n+i]);
        vala[i+1]=vala[i]+a[n+i]-que.top();
        que.pop();
        que2.push(a[2*n-1-i]);
        valb[i+1]=valb[i]-que2.top()+a[2*n-1-i];
        que2.pop();
    }
    DEBUG{
        rep(i,n+1)cout << vala[i] << " ";
        cout << endl;
        rep(i,n+1)cout << valb[i] << " ";
        cout << endl;

    }
    ll res=vala[0]-valb[n];
    rep(i,n){
        res=max(res,vala[i+1]-valb[n-i-1]);
    }
    cout << res << endl;
    return 0;
}
