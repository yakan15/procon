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
    int n,t;
    cin>>n>>t;
    int a[n];
    int a_max[n];
    int val[n-1];
    rep(i,n){cin>>a[i];}
    a_max[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){a_max[i]=max(a_max[i+1], a[i]);}
    int max_dif=0;
    rep(i,n-1){
        val[i] = max(0, a_max[i+1]-a[i]);
        max_dif = max(max_dif, val[i]);
    }
DEBUG{cout << "max dif" << max_dif << endl;}
    set<int> sell_st;
    unordered_map<int, vector<int> > valv;
    rep(i,n){
        if(sell_st.find(a[i])!=sell_st.end()){
            DEBUG{cout << "pass" << endl;}
            valv[a[i]-max_dif].push_back(1);
        }
        if(val[i]==max_dif){
            valv[a[i]].push_back(0);
            sell_st.insert(a[i]+max_dif);
        }
    }
    DEBUG{printf("test\n");}
    DEBUG{cout << valv.size() << endl;}
    DEBUG{
        for(auto x:sell_st){cout << x << " ";}
        cout << endl;
    }
    int res=0;
    for(auto v:valv){
        DEBUG{cout << v.second.size() << " " << endl;}
        int now=0;
        int cnt[2]={};
        for(auto x:v.second){
            if(now&&!x){
                res += min(cnt[0],cnt[1]);
                cnt[0]=0;
                cnt[1]=0;
            }
            cnt[x]++;
            now=x;
        }
        res += min(cnt[0], cnt[1]);
    }
    cout << res << endl;
    return 0;

}
