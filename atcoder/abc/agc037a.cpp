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
    string s;cin>>s;
    ll cnt=1,cur=0;
    ll n = s.size();
    while(cur<n-1){
        if(s[cur]==s[cur+1]){
            if(cur<n-2){
                cnt++;
            }
            cur += 3;
            if(cur<=n-1){
                cnt++;
            }
        }else{
            cur++;cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
