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
    vector<int> l;
    int n = s.size();
    int res[n]={};
    int cnt=0,cur=0,cnt2=0;
    int point;
    while(true){
        cnt=0;
        while(cur<n&&s[cur]=='R'){
            cnt++;
            cur++;
        }
        point = cur;
        cur++;
        while(cur<n&&s[cur]=='L'){
            cnt2++;
            cur++;
        }
        res[point-1]=cnt/2+cnt%2+cnt2/2+cnt2%2;
        res[point]=cnt/2+cnt2/2+1;
        cnt=0;cnt2=0;
        if(cur>=n){break;}
    }
    rep(i,n){
        cout << res[i];
        if(i==n-1){cout << endl;}
        else{cout << " ";}
    }
    return 0;
}
