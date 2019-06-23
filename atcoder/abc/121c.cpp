#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
int main(void) {
    cin >> n >> m;
    vector<pair<ll,ll> > ab;
    rep(i,n){
        ll tmpa,tmpb;
        cin >> tmpa >> tmpb;
        ab.push_back(make_pair(tmpa,tmpb));
    }
    sort(ab.begin(),ab.end());
    ll cnt=0,cur=0;
    ll res=0;
    while(true){
        if(cnt+ab[cur].second>=m){
            res += ab[cur].first*(m-cnt);
            break;
        }else{
            res += ab[cur].first*ab[cur].second;
            cnt += ab[cur].second;
            cur++;
        }
    }
    cout << res << endl;
    return 0;
}
