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
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    int cnt[n]={};
    rep(i,m){
        cin>>a[i]>>b[i];
        cnt[a[i]-1]++;
        cnt[b[i]-1]++;
    }
    rep(i,n){
        if(cnt[i]%2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
