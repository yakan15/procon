#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int abc_to_i(char c){
    return int(c-'a');
}

int main(void) {
    string s;
    ll k;
    cin>>s>>k;
    ll lim=1LL<<62;
    int s_len=s.size();
    int prev[26]={};
    DEBUG{cout << s.size() << endl;}
    vector<int> places[26];
    bool flg[26]={};
    ll dp[s_len+1]={};
    // dp[s_len]=0;
    for(int i=s_len-1;i>=0;i--){
        places[abc_to_i(s[i])].push_back(i);
        if(!flg[abc_to_i(s[i])]){
            dp[i]++;
            flg[abc_to_i(s[i])]=true;    
        }
        if(dp[i+1]>=lim){
            dp[i]=lim;
            continue;
        }
        dp[i]+=dp[i+1]*2;
        if(prev[abc_to_i(s[i])]!=0){
            dp[i]-=dp[prev[abc_to_i(s[i])]+1];
        }
        prev[abc_to_i(s[i])]=i;
    }
    rep(i,26){
        if(!places[i].empty()){
            sort(places[i].begin(),places[i].end());
        }
    }
    DEBUG{
        rep(i,26){
            cout << "size : " << places[i].size() << endl;
            for(auto x:places[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    DEBUG{
        rep(i,s_len)cout << dp[i] << " ";
        cout << endl;
    }
    string res = "";
    ll remain=k;
    int now=0;
    if(dp[0]<k){
        cout << "Eel" << endl;
        return 0;
    }
    while(remain>0){
        DEBUG{cout << "remain : "<< remain<<endl;}
        rep(i,26){
            auto pt = lower_bound(places[i].begin(),places[i].end(),now);
            if(pt!=places[i].end()){
                int cur = *pt;
                DEBUG{cout << "cur : " << cur << endl;
                    cout << "dp : " << dp[cur+1]<<endl;
                }
                if(remain<=dp[cur+1]+1){
                    res += s[cur];
                    // if(remain==dp[cur+1]){
                    //     remain=0;
                    // }
                    remain--;
                    DEBUG{cout << "1 remain : " << remain<<endl;}

                    now=cur+1;
                    break;
                }
                remain-=dp[cur+1]+1;
                DEBUG{cout << "2 remain : " << remain<<endl;}
            }
            if(i==25){
                cout << "Eel" << endl;
                return 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}
