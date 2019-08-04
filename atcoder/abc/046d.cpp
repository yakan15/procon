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
    int cnt=0;
    rep(i,s.size()){
        if(s[i]=='g'){
            cnt++;
        }else{
            cnt--;
        }
    }
    cout << cnt/2 << endl;
    return 0;
}
