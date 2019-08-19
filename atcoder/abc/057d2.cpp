#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

ll combi(ll n, ll k){
    ll res=1;
    ll cnt=1;
    while(k>0){
        res *= n-cnt+1;
        res /= cnt;
        k--;
        cnt++;
    }
    return res;
}

int main(void) {
    ll n,a,b;
    cin>>n>>a>>b;
    map<ll, ll, greater<ll> > mp;
    rep(i,n){
        ll tmp;cin>>tmp;
        mp[tmp]++;
    }
    ll cnt=0;
    ll cntres=0;
    double mean=0;
    DEBUG{
        for(auto x:mp){
            cout << "value : " << x.first << " cnt : "<< x.second<<endl;
        }
    }
    bool first=true;
    for(auto x:mp){
        if(x.second+cnt>=a){
            if(first){
                for(ll i=a;i<=min(x.second, b);i++){
                    cntres += combi(x.second,i);                    
                }
                mean = x.first;
            }else{
                DEBUG{cout << "sum : " << mean << endl;}
                mean += x.first*(a-cnt);
                mean /= a;
                cntres = combi(x.second, a-cnt);
            }
            break;
        }else{
            cnt += x.second;
            mean += x.second*x.first;
            first = false;
        }
    }
    printf("%lf\n",mean);
    cout << cntres << endl;
    return 0;
}
