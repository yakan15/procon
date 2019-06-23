#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
vector<pair<ll, ll> > ba;
int main(void) {
    cin >> n;
    ll cnta=0;
    rep(i,n){
        ll tmpb,tmpa;
        cin >> tmpa >> tmpb;
        ba.push_back(make_pair(tmpb,tmpa));
    }
    sort(ba.begin(),ba.end());
    rep(i,n){
        cnta+=ba[i].second;
        DEBUG{
            printf("b : %lld, a : %lld\n",ba[i].first,cnta);
        }
        if(cnta>ba[i].first){
            cout << "No" << endl;
            return 0;    
        }
    }
    cout << "Yes" << endl;
    return 0;
}
