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
    string s;
    cin>>s;
    ll res=0;
    int n=s.size();
    rep(i,n){
        if(s[i]=='U'){
            res += 2*i+n-1-i;
        }else{
            res += (n-1-i)*2+i;
        }
    }
    cout << res << endl;
    return 0;
}
