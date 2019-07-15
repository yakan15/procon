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
    string s[2];
    cin >> n>>s[0]>>s[1];
    ll res=1;
    int cnt=0;
    int state=0;
    while(cnt<n){
        if(s[0][cnt]!=s[1][cnt]){
            if(state==2){
                res*=3;
            }else{
                res*=(3-state)*(2-state);
            }
            state=2;
            cnt+=2;
        }else{
            res*=3-state;
            state=1;
            cnt++;
        }
        DEBUG{cout <<"res : " << res << endl;}
        DEBUG{cout <<"cnt : " << cnt << endl;}
        res%=MOD;
    }
    cout << res << endl;
    return 0;
}
