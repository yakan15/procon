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
    rep(i,s.size()){
        if(i%2==0&&(s[i]=='R'||s[i]=='U'||s[i]=='D')){
            continue;
        }else if(i%2==1&&(s[i]=='L'||s[i]=='U'||s[i]=='D')){
            continue;
        }
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
