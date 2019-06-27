#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
ll d,g;
int main(void) {
    cin >> d >> g;
    ll task[d][2];
    vector<ll> perm;
    rep(i,d){
        cin >> task[i][0] >> task[i][1];
    }
    rep(i,d){
        perm.push_back(i);
    }
    ll res=1LL<<60;
    do {
        ll sum=0,cnt=0;
        for(auto x:perm){
            if(sum+(x+1)*100*task[x][0]+task[x][1]>=g){
                cnt+=min((g-sum-1)/((x+1)*100)+1,task[x][0]);
                if(res>cnt)res=cnt;
                break;
            }
            cnt+=task[x][0];
            sum+=(x+1)*100*task[x][0]+task[x][1];
        }
    }while(next_permutation(perm.begin(),perm.end()));
    cout << res << endl;
    return 0;
}
