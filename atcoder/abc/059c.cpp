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
    ll n;cin>>n;
    vector<ll> a(n);rep(i,n){cin>>a[i];}
    function<ll()> solve = [&](){
        ll sum = 0,cnt=0;
        rep(i,n){
            if(i==0){
                sum = a[0];
                continue;
            } 
            if(sum>0&&sum+a[i]>=0){
                cnt += sum+a[i]+1;
                sum=-1;
            }else if(sum<0&&sum+a[i]<=0){
                cnt += -(sum+a[i])+1;
                sum=1;
            }else{
                sum += a[i];
            }
        }
        DEBUG{
            printf("cnt: %lld\n",cnt);
        }
        return cnt;
    };
    ll res;
    if(a[0]==0){
        a[0]=1;
        res = solve();
        a[0]=-1;
        chmin(res, solve());
        res++;
    }else if(a[0]>0){
        res = solve();
        ll tmp = a[0];
        a[0] = -1;
        DEBUG{
            cout << tmp << endl;
            cout << res << endl;
        }
        chmin(res, solve()+tmp+1);
        
    }else{
        res = solve();
        ll tmp = a[0];
        a[0] = 1;
        chmin(res, solve()-tmp+1);
    }
    cout << res << endl;
    return 0;
}
