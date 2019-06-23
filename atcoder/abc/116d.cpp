#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,k;
int main(void) {
    cin >> n >> k;
    vector<pair<ll,ll> > dt;
    priority_queue<ll, vector<ll>, greater<ll> > q;
    bool flg[100005]={};
    ll cnt=0,res[k+1]={},tmp=0;
    rep(i,n){
        ll tmpt,tmpd;
        cin >> tmpt >> tmpd;
        dt.push_back(make_pair(tmpd,tmpt));
    }
    sort(dt.begin(),dt.end(),greater<pair<ll,ll> >());
    rep(i,k){
        tmp+=dt[i].first;
        if(flg[dt[i].second]){
            q.push(dt[i].first);
        }else{
            cnt++;
            flg[dt[i].second]=true;
        }
    }
    res[cnt]=tmp;
    DEBUG{
        cout << "cnt " << cnt << "res " << tmp << endl;
    }
    ll cur=0,out=0;
    while(cur<n&&cnt<k&&!q.empty()){
        if(flg[dt[cur].second]){
            cur++;
            continue;
        }
        cnt++;
        out=q.top();
        q.pop();
        res[cnt]=res[cnt-1]-out+dt[cur].first;
        flg[dt[cur].second]=true;
        cur++;
    }
    ll r=0;
    rep(i,k+1){
        if(res[i]!=0)r=max(r,res[i]+i*i);
    }
    cout << r << endl;
    return 0;
}
