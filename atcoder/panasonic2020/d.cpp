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
    int n;
    cin>>n;
    vector<string> res;
    function<void(string)> rec = [&] (string s) {
        if (s.size()==n) {
            res.push_back(s); 
            return;
        }
        int mx='a';
        for(auto x:s) {
            chmax(mx, int(x));
        }
        int nxt = 'a';
        while(nxt<=mx+1) {
            rec(s + string(1,nxt));
            nxt++;
        }
        return;
    };
    rec("a");
    sort(begin(res), end(res));
    for(auto x:res) {
        cout << x << endl;
    }
    return 0;

}
