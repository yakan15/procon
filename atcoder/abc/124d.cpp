#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> val;
    int cnt=0;
    char v=S[0];
    int flg=int(v=='1');
    rep(i,N){
        if(S[i]==v)cnt++;
        else{
            val.push_back(cnt);
            cnt=1;
            v=S[i];
        }
        if(i==N-1)val.push_back(cnt);
    }
    vector<int> sum_val;
    int tmp=0;
    sum_val.push_back(0);
    for(auto x:val){
        tmp+=x;
        sum_val.push_back(tmp);
    }
    // K = min(K,int(sum_val.size()));
    // DEBUG{
    //     cout << K << endl;
    //     rep(i,sum_val.size()){
    //         cout << sum_val[i] << endl;
    //     }
    // }
    int res=0;
    rep(i,N) {
        if(flg){
            if(i+2*K>=sum_val.size())continue;
            else if(i+2*K+1>=sum_val.size()){
                res = max(res, sum_val[i+2*K]-sum_val[i]);
                continue;
            }
            res = max(res, sum_val[i+2*K+1]-sum_val[i]);
        }
        else{
            if(i+2*K>=sum_val.size())continue;
            res = max(res, sum_val[i+2*K]-sum_val[i]);
        }
        flg =1-flg;
    }
    if(res==0){
        res=sum_val[sum_val.size()-1];
    }
    cout << res << endl;
    return 0;
}
