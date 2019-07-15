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
    string s;
    cin>>n>>s;
    int cnt[2]={};
    int cur=0;
    // while(cur<n&&s[cur]==')'){
    //     cnt[0]++;
    //     cur++;
    // }
    while(cur<n){
        if(cnt[1]==0&&s[cur]==')')cnt[0]++;
        else if(s[cur]=='(')cnt[1]--;
        else cnt[1]++;
        cur++;
    }
    rep(i,cnt[0])s='('+s;
    if(cnt[1]>0)rep(i,cnt[1])s='('+s;
    else rep(i,-cnt[1])s+=')';
    cout << s << endl;
    return 0;
}
