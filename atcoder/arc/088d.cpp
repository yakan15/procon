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
    string s;cin>>s;
    int n = s.size();
    function<bool(int)> check = [&](int x){
        DEBUG{
            printf("%d\n",x);
        }
        int cnt = 0;
        int n_rev=0;
        vector<int> chk(n,0);
        rep(i,n){
            n_rev -= chk[i];
            if((s[i]-'0'+n_rev)%2!=0){
                if(i+x-1<n){
                    n_rev++;
                    if(i+x<n)chk[i+x]=1;
                }else{
                    break;
                }
            }
            cnt++;
        }
        return cnt>=x;
    };
    int from = 1,to=n;
    while(to-from>1){
        int mid = (to+from)/2;
        if(check(mid)){
            from = mid;
        }else{
            to = mid;
        }
    }
    cout << (check(to) ? to : from) << endl;
    return 0;
}
