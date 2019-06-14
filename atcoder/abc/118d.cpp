#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool strnum_greater(string a, string b){
    if(a.size()!=b.size())return a.size() > b.size();
    rep(i,a.size()){
            if(a[i]!=b[i])return a[i]>b[i];
    }
    return false;

}

int main(void) {
    int n,m;
    cin >> n >> m;
    vector<int> available_n(8,0);
    rep(i,m){
        int tmp;
        cin >> tmp;
        if(tmp==3||tmp==2||tmp==5)available_n[5]=max(available_n[5],tmp);
        if(tmp==1)available_n[2]=max(available_n[2],tmp);
        if(tmp==4)available_n[4]=max(available_n[4],tmp);
        if(tmp==7)available_n[3]=max(available_n[3],tmp);
        if(tmp==8)available_n[7]=max(available_n[7],tmp);
        if(tmp==6||tmp==9)available_n[6]=max(available_n[6],tmp);
    }

    vector<string> dp(n+1,"0");
    rep(i,n){
        if(i!=0&&dp[i]=="0")continue;
        for(int j=2;j<=7;j++){
            if(i+j>n)continue;
            if(available_n[j]!=0&&strnum_greater(dp[i]+to_string(available_n[j]),dp[i+j]))dp[i+j]=dp[i]+to_string(available_n[j]);
        }
    }
    dp[n].erase(dp[n].begin());
    cout << dp[n] << endl;

    return 0;
}
