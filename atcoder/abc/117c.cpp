#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
vector<ll> x;
int main(void) {
    cin >> n >> m;
    
    rep(i,m){
        ll tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    if(n>=m){
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(),x.end());
    vector<pair<ll,ll> > diff;
    ll cnt=m-n;
    rep(i,m-1){
       diff.push_back(make_pair(x[i+1]-x[i],i)); 
    }
    sort(diff.begin(),diff.end(),greater<pair<ll,ll> >());
    // DEBUG{
    //     rep(i,m){
    //         cout << diff[i].first << endl;
    //     }
    // }
    ll res=0;
    bool koma[m]={};
    koma[0]=true;
    rep(i,n-1){
        koma[diff[i].second+1]=true;
    }
    // DEBUG{
    //     rep(i,m){cout << koma[i] << endl;}
    // }
    for(int i=1;i<m;i++){
        if(!koma[i])res+=x[i]-x[i-1];
    }
    cout << res << endl;
    return 0;
}
