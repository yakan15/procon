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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    string s[n];
    rep(i,n){cin>>s[i];}
    ll res=0;
    rep(i,n){
        bool flg=true;
        rep(j,n){
            rep(k,n){
                if((j+i)%n==k){continue;}
                flg &= (s[(j+i)%n][k] == s[(k+i)%n][j]);
            }
        }
        if(flg){
            res += n;
        }
    }
    cout << res << endl;
    return 0;
}
