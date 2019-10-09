#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    int lim = 1e+5 + 10;
    vector<int> x(lim,0);
    vector<int> count_mod(lim,0), count_mod2(lim,0);
    rep(i,n){
        int a;
        cin>>a;
        x[a]++;
    }
    rep(i,lim){
        count_mod[i%m] += x[i]/2;
        count_mod2[i%m] += x[i]%2;
    }
    vector<bool> checked(m,false);
    int res=0;
    rep(i,m){
        if(i==0||i*2==m){
            res += count_mod[i]+count_mod2[i]/2;
            continue;
        }
        if(!checked[i]){
            DEBUG{
                printf("set: %d, %d\n",i,m-i);
                printf(" %d, %d\n",count_mod[i],count_mod2[i]);
                printf(" %d, %d\n",count_mod[m-i],count_mod2[m-i]);
            }
            int tmp = min(count_mod2[i], count_mod2[m-i]);
            res += tmp;
            if(count_mod2[i]<count_mod2[m-i]){
                tmp = count_mod2[m-i]-tmp;
                res += min(count_mod[i]*2, tmp);
                res += max((count_mod[i]*2-tmp)/2,0);
                res += count_mod[m-i];
            }else{
                tmp = count_mod2[i]-tmp;
                res += min(count_mod[m-i]*2, tmp);
                res += max((count_mod[m-i]*2-tmp)/2,0);
                res += count_mod[i];
            }
        }
        checked[i] = checked[m-i] = true;
    }
    cout << res << endl;
    return 0;
}
