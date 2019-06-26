#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
string s;
ll k;
int main(void) {
    cin >> s >> k;
    ll cnt=0;
    char res;
    rep(i,s.size()){
        if(s[i]=='1')cnt++;
        else{
            res=s[i];
            break;
        }
    }
    if(k<=cnt){
        cout << 1 << endl;
    }else{
        cout << res << endl;
    }
    return 0;
}
