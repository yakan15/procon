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
    ll n;
    cin>>n;
    ll a[n+1];
    rep(i,n)cin>>a[i+1];
    int box[n+1]={};
    vector<int> res;
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=2;j*i<=n;j++){
           cnt += box[j*i]; 
        }
        if(cnt%2!=a[i]){
            box[i]=1;
            res.push_back(i);
        }
    }
    cout << res.size()<<endl;
    rep(i,res.size())cout << res[i] << endl;
    return 0;
}
