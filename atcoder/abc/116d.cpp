#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,k;
vector<pair<ll, ll> > neta;
int main(void) {
    cin >> n >> k;
    ll tmp[2]={};
    priority_queue<ll> pq=priority_queue<ll>();
    ll f[n+1]={};
    bool select[n+1]={};
    set<ll> selected,duplicate;
    rep(i,n){
        cin >> tmp[1] >> tmp[0];
        neta.push_back(make_pair(tmp[0],tmp[1]));
    }
    sort(neta.begin(), neta.end(), greater<pair<ll, ll> >());
    ll res=0,cnt=0;
    rep(i,k){
        res += neta[i].first;
        if(select[neta[i].second])pq.push(-1*neta[i].first);
        else {
            select[neta[i].second]=true;
            cnt++;
        }
    }
    DEBUG{
        printf("size : %lld, g : %lld\n",cnt,res+cnt*cnt);
    }
    DEBUG{
        rep(i,n+1){
            printf("i:%d, selected:%d\n",i,int(select[i]));
        }
    }
    ll now=k;
    f[cnt]=res;
    ll diff;
    while(pq.size()!=0&&now<n){
        diff=0;
        while(select[neta[now].second]&&now<n){
            now++;
        }
        if(now>=n)break;
        diff += pq.top();
        pq.pop();
        diff += neta[now].first;
        select[neta[now].second]=true;
        cnt++;
        f[cnt]=f[cnt-1]+diff;
        DEBUG{
            printf("t : %lld, now : %lld diff : %lld\n",neta[now].second, now, diff);
        }
    }
    res=0;
    DEBUG{
        rep(i,n){
            printf("size : %d, res : %lld\n",i, f[i]+i*i);
        }
    }
    rep(i,n+1){
        if(f[i]!=0&&f[i]+i*i>res)res=f[i]+i*i;
    }
    cout << res << endl;
    return 0;
}
