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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    rep(i,n){cin>>a[i];}
    ll sum=0;
    rep(i,n){sum+=a[i];}
    vector<int> divs;
    rep(i,int(sqrt(sum))+1){
        if(sum%(i+1)==0){
            divs.push_back((i+1));
            divs.push_back(sum/(i+1));
        }
    }
    sort(divs.begin(),divs.end(),greater<int>());
    DEBUG{
        rep(i,divs.size()){
            cout << divs[i] << endl;
        }
    }
    for(auto x:divs){
        ll amari[n]={};
        ll cumsum[n+1]={};
        ll cumsum2[n+1]={};
        rep(i,n){
            cumsum[i]=cumsum2[i]=0;
        }
        rep(i,n){
            amari[i]=a[i]%x;
        }
        sort(amari,amari+n);
        rep(i,n){
            cumsum[i+1]=cumsum[i]+amari[i];
            cumsum2[i+1]=cumsum2[i]+(amari[i]==0 ? 0 : x-amari[i]);
        }
        DEBUG{
            rep(i,n+1){
                cout << cumsum[i] << " ";
            }
            cout << endl;
            rep(i,n+1){
                cout << cumsum2[i] << " ";
            }
            cout << endl;
        }
        rep(i,n){
            if(cumsum[i]==cumsum2[n]-cumsum2[i]&&cumsum[i]<=k){
                cout << x << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    return 0;
}
