#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
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
    ll n,m,q;cin>>n>>m>>q;
    vector<ll> a(q),b(q),c(q),d(q);
    rep(i,q) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;b[i]--;
    }
    ll res = 0;
    function<void(string)> solve = [&] (string s) {
        if (s.size()==n) {
            ll sum = 0;
            rep(i,q) {
                if (s[b[i]] - s[a[i]] == c[i]) {
                    sum += d[i];
                }
            }
            chmax(res, sum);
            return;
        }
        ll num;
        if (s.size()==0) {
            num = 1;
        } else {
            num = s[s.size()-1] - '0';
        }
        repr(i,num,m+1) {
            string tmp = s;
            tmp += (i+'0');
            solve(tmp);
        }
    };
    solve("");
    cout << res << endl;
    return 0;
}
