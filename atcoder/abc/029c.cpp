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
    int n;cin>>n;
    rep(i, int(pow(3,n))) {
        vector<int> v;
        int tmp = i;
        rep(j, n) {
            v.push_back(tmp%3);
            tmp /=3; 
        }
        for(int j=n-1;j>=0;j--) {
            string s(1, 'a'+v[j]);
            cout << s;
        }
        cout << endl;
    }
    return 0;
}
