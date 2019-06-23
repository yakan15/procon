#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll x,y,z,k;
    vector<ll> a,b,c;
    cin >>x>>y>>z>>k;
    ll tmp;

    rep(i,x){
        cin >> tmp;
        a.push_back(tmp);
    }
    rep(i,y){
        cin >> tmp;
        b.push_back(tmp);
    }
    rep(i,z){
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    sort(c.begin(),c.end(),greater<ll>());
    vector<ll> res;
    rep(i,x){
        rep(j,y){
            if(i*j>3000)break;
            rep(l,z){
                if(i*j*l>3000)break;
                res.push_back(a[i]+b[j]+c[l]);
            }
        }
    }
    sort(res.begin(),res.end(),greater<ll>());
    rep(i,k){
        cout << res[i] << endl;
    }
    return 0;
}
