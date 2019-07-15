#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

ll n,z,w;

int main(void) {
    cin >>n>>z>>w;
    ll score[n];
    ll minmax_a[n],minmax_b[n];
    rep(i,n){
        cin >> score[i];
    }
    if(n==1){
        cout << abs(score[0]-w) << endl;
        return 0;
    }
    // minmax_a[n-1]=abs(score[n-2]-score[n-1]);
    // minmax_b[n-1]=abs(score[n-2]-score[n-1]);
    for(int i=n-1;i>=0;i--){
        ll tmp_a=0,tmp_b=0;
        if(i==0){
            tmp_a=abs(w-score[n-1]);
        }else tmp_a=abs(score[i-1]-score[n-1]);
        for(int j=i+1;j<n;j++){
            tmp_a = max(tmp_a, minmax_b[j]);
        }
        DEBUG{cout << "a : " << tmp_a << endl;}
        minmax_a[i]=tmp_a;
        if(i==0)continue;
        tmp_b = abs(score[i-1]-score[n-1]);
        for(int j=i+1;j<n;j++){
            tmp_b = min(tmp_b, minmax_a[j]);
        }
        DEBUG{cout << "b : " << tmp_b << endl;}
        minmax_b[i]=tmp_b;
    }
    cout << minmax_a[0] << endl;
    return 0;
}
