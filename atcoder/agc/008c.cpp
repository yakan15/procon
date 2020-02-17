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
    ll i,o,t,j,l,s,z;
    cin>>i>>o>>t>>j>>l>>s>>z;
    ll res = 0;
    res += o;
    if (i==0||j==0||l==0) {
        res += i/2*2 + j/2*2 + l/2*2;
    }
    else if (!(i%2&&j%2&&l%2)&&(i+j+l)%2||
                !(i%2==0&&j%2==0&&l%2==0)&&(i+j+l)%2==0) {
        res += i+j+l-1;
    }
    else {
        res += i+j+l;
    }
    cout <<res << endl;
    return 0;
}
