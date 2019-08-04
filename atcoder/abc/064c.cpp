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
    int n;
    cin >> n;
    int cnt[9]={};
    rep(i,n){
        int tmp;cin>>tmp;
        cnt[min(tmp/400,8)]++;
    }
    int res=0;
    rep(i,8){res+=int(cnt[i]!=0);}
    cout << max(res,1) << " " << res+cnt[8] << endl;
    return 0;
}
