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
    ll k,n;
    cin>>n>>k;
    vector<ll> xs,ys;
    ll xy[n][2]={};
    rep(i,n){
        ll tx,ty;
        cin >> tx >> ty;
        xs.push_back(tx);
        ys.push_back(ty);
        xy[i][0]=tx;
        xy[i][1]=ty;
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    map<ll, ll> xmp,ymp;
    bool poll[n][n]={};
    rep(i,n){
        xmp[xs[i]]=i;
        ymp[ys[i]]=i;
    }
    rep(i,n){
        poll[xmp[xy[i][0]]][ymp[xy[i][1]]]=true;
    }
    ll sum[n][n+1]={};
    rep(i,n){
        ll tmp=0;
        rep(j,n){
            if (poll[i][j])tmp++;
            sum[i][j+1]=tmp;
        }
    }
    ll res=1LL<<62;
    rep(pivot_x,n)rep(pivot_y,n){
        for(ll width=1;pivot_x+width<n;width++){
            for(ll height=1;pivot_y+height<n;height++){
                ll np=0;
                for(ll i=0;i<=width;i++){
                    np+=sum[pivot_x+i][pivot_y+height+1]-sum[pivot_x+i][pivot_y];
                }
                DEBUG{
                    cout << np << endl;
                }
                if(np==k)res=min(res, ll(xs[pivot_x+width]-xs[pivot_x])*ll(ys[pivot_y+height]-ys[pivot_y]));
            }
        }
    }
    cout << res << endl;
    return 0;
}
