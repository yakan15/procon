#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,a[3];
vector<string> strs;
void dfs(string s){
    if(s.size()==n-1){
        rep(i,4){
            strs.push_back(s+to_string(i));
        }
    }else{
        rep(i,4){
            dfs(s+to_string(i));
        }
    }
}

int main(void) {
    cin >> n;
    rep(i,3)cin >> a[i];
    int l[n];
    rep(i,n)cin >> l[i];
    dfs("");
    // DEBUG{
    //     cout << strs.size() << endl;
    // }
    int cost,res=INT_MAX;
    rep(i,strs.size()){
        int cnt[3]={};
        int tmp=stoi(strs[i]);
        // DEBUG{
        //     cout << i << endl;
        //     cout << tmp << endl;
        // }
        int cur=0;
        cost=0;
        rep(j,n){
            cur=tmp%10;
            // DEBUG{cout << cur << endl;}
            tmp/=10;
            if(cur==3)continue;
            else if(cnt[cur]!=0){
                cost+=10;
            }
            cnt[cur]+=l[j];
        }
        rep(j,3){
            if(cnt[j]==0){
                cost=INT_MAX;
                break;
            }
            cost += abs(cnt[j]-a[j]);
        }
        if(cost<res)res=cost;
    }
    cout << res << endl;
    return 0;
}
