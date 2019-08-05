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
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int> > targets[n];
    ll d[n];
    bool negflg[n]={};
    d[0]=0;
    rep(i,n-1){d[i+1]=1LL<<60;}
    rep(i,m){
        int ta,tt,tc;
        cin>>ta>>tt>>tc;
        ta--;tt--;
        targets[ta].push_back(make_pair(tt,-tc));
    }
    rep(i,n){
        rep(j,n){
            for(auto x:targets[j]){
                if(d[x.first] > d[j] + x.second){
                    d[x.first] = d[j] + x.second;
                    if(i==n-1){
                        negflg[x.first]=true;
                    }
                }
            }
        }
    }
    queue<int> neg;
    rep(i,n){if(negflg[i])neg.push(i);}
    while(!neg.empty()){
        int cur=neg.front();
        neg.pop();
        for(auto x:targets[cur]){
            if(!negflg[x.first]){
                negflg[x.first]=true;
                neg.push(x.first);
            }
        }
    }
    cout << (negflg[n-1] ? "inf" : to_string(-d[n-1])) << endl;
    return 0;
}
