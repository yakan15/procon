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
    cin >> s;
    int cnt0=0,cnt1=0;
    rep(i,s.size()){
        if(s[i]=='0')cnt0++;
        else cnt1++;
    }
    cout << max(cnt0,cnt1) << endl;
    return 0;
}
