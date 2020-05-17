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
    string n;cin>>n;
    int res = 0;
    bool pls = false;
    for(int i=n.size()-1;i>=0;i--) {
        int now = n[i] - '0';
        if (pls) now++;
        if (now>5) {
            res += 10-now;
            pls = true;
        }
        else if (now==5&&i>0 && n[i-1]-'0'>=5) {
            res += 5;
            pls = true;
        }
        else {
            res += now;
            pls = false;
        }
    }
    if (pls) res++;
    cout << res << endl;
    return 0;
}
