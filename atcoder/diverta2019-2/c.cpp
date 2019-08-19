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
    ll n;cin>>n;
    vector<ll> plus,minus;
    vector<pair<ll,ll> > control;
    ll res=0;
    rep(i,n){
        ll tmp;cin>>tmp;
        tmp > 0 ? plus.push_back(tmp) : minus.push_back(tmp);
    }
    ll np = plus.size();
    ll nm = minus.size();
    if(np>0&&nm==0){
        if(np==2){
            res = max(plus.at(0),plus.at(1)) - min(plus.at(0),plus.at(1));
            cout << res << endl;
            cout << max(plus.at(0),plus.at(1)) << " " << min(plus.at(0),plus.at(1)) << endl;
        }else{
            sort(plus.begin(),plus.end());
            rep(i,np-1){
                res += plus.at(i+1);
            }
            res -= plus.at(0);
            cout << res << endl;
            rep(i,np-2){
                cout << plus.at(0) <<" " << plus.at(i+1) << endl; 
                plus.at(0) -= plus.at(i+1);
            }
            cout << plus.at(np-1) << " " << plus.at(0) << endl;
        }
    }else if(np>0&&nm>0){
        rep(i,np){
            res += plus.at(i);
        }
        rep(i,nm){
            res -= minus.at(i);
        }
        cout << res << endl;
        for(ll i=1;i<np;i++){
            cout << minus.at(0) << " " << plus.at(i) << endl;
            minus.at(0) -= plus.at(i);
        }
        for(ll i=0;i<nm;i++){
            cout << plus.at(0) << " " << minus.at(i) << endl;
            plus.at(0) -= minus.at(i);
        }
    }else{
        sort(minus.begin(),minus.end());
        rep(i,nm-1){
            res -= minus.at(i);
        }
        res += minus.at(nm-1);
        cout << res << endl;
        rep(i,nm-1){
            cout << minus.at(n-1) << " " << minus.at(i) << endl;
            minus.at(n-1) -= minus.at(i);
        }
    }
    return 0;
}
