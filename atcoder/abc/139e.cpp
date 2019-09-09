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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<vector<ll> > a(n,vector<ll>(n-1,0));
    vector<queue<ll> > que(n);
    rep(i,n){
        rep(j,n-1){
            cin>>a.at(i).at(j);
            a.at(i).at(j)--;
        }
    }
    rep(i,n){
        for(int j=n-2;j>=0;j--){
            que.at(i).push(a.at(i).at(j));
        }
    }
    ll cnt = n*(n-1)/2;
    ll tmp1,tmp2;
    ll days[n]={};    
    while(cnt>0){
        ll cur = 0;
        bool flg=false;
        while(cur<n){
            if(que[cur%n].size()!=0&&que[que[cur%n].front()].front()==cur%n){
                tmp1 = que[que[cur%n].front()].front();
                tmp2 = que[cur%n].front();
                days[tmp1] = days[tmp2] = max(days[tmp1],days[tmp2])+1;
                que[que[cur%n].front()].pop();
                que[cur%n].pop();
                cnt--;
                flg = true;
            }else{
                cur++;
            }
        }
        if(!flg){
            cout << -1 << endl;
            return 0;
        }
    }
    ll res=0;
    rep(i,n){
        res = max(res,days[i]);
    }
    cout << res << endl;
    return 0;
}
