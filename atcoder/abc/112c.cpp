#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// ll n;

ll height(ll x, ll y, ll h, ll cx, ll cy){
    return max(h - abs(x-cx) - abs(y-cy),ll(0));
}

int main(void) {
    ll n;
    cin >> n;
    ll xyh[3][100]={};
    ll h=0;
    rep(i,n){
        cin >> xyh[0][i] >> xyh[1][i] >> xyh[2][i];
        if(xyh[2][i]>h)h=xyh[2][i];
    }
    ll res[2]={};
    rep(i,101){
        rep(j,101){
            for(ll k=h;k<h+200;k++){
                bool ok = true;
                rep(l,n){
                    if(height(i,j,k,xyh[0][l],xyh[1][l])!=xyh[2][l]){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    printf("%d %d %lld\n",i,j,k);
                    return 0;
                }
            }
        }
    }

    return 0;
}
