#include <bits/stdc++.h>
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)

int main(void) {
    string s,t;cin>>s>>t;
    unordered_map<char, vector<ll> > mp;
    unordered_map<char, ll> mp2;
    ll n = s.size(),m=t.size();
    rep(i,n){
        mp[s.at(i)].push_back(i);
        mp2[s.at(i)]++;
    }
    rep(i,m){
        if(mp2[t.at(i)]==0){
            cout << -1 << endl;
            return 0;
        }
    }
    ll res = 0;
    ll now = 0;
    ll cur = 0;
    rep(i,m){
        auto valcur = lower_bound(mp.at(t.at(i)).begin(), mp.at(t.at(i)).end(), res%n);
        DEBUG{
            cout << t.at(i) << " ";
        }
        if(valcur == mp.at(t.at(i)).end()){
            DEBUG{
                printf("next\n");
            }
            res += n + mp.at(t.at(i)).at(0) - res % n;
        }else{
            DEBUG{
                printf("same\n");
            }
            res += *valcur - res % n;
        }
        DEBUG{
            cout << res << endl;
        }
        res++;
    }
    cout << res << endl;
    return 0;
}
