#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string s;
int main(void) {
    cin >> s;
    int n=s.size();
    int cnt[2]={};
    rep(i,n){
        if(s[i]=='0')cnt[0]++;
        else cnt[1]++;
    }
    cout << min(cnt[0],cnt[1])*2 << endl;

    return 0;
}
