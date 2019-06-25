#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll n;
    vector<pair<ll,ll> > xy;
    rep(i,n){
        ll tx,ty;
        cin >> tx >> ty;
        xy.push_back(make_pair(tx,ty));
    }
    rep(i,n-1){
        if(abs(xy[i].first+xy[i].second)%2!=abs(xy[i+1].first+xy[i+1].second)){
            cout << -1 << endl;
            return 0;
        }
    }
    
    return 0;
}
