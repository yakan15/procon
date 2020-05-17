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

ll n;
string s, end_str;
map<string, ll> mp;
ll solve(ll l, ll r, string selected, ll count) {
    // cout << "l: " << l << ", r: " << r << endl;
    // cout << count << endl;
    // cout << selected << endl;
    // if (mp.find(selected) != mp.end()) {return mp[selected];}
    if (selected == end_str) {return 1LL;}
    ll res = 0;
    for(ll i=l;i<n+count;i++) {
        // cout << i;
        if (selected[i]=='0') {
            string tmp = selected;
            tmp[i] = '1';
            for (ll j=r;j>=n-count-1;j--) {
                string tmp2 = tmp;
                if (tmp2[j]=='0' && s[i] == s[j]) {
                    tmp2[j] = '1';
                    res += solve(i+1, j-1, tmp2, count+1);
                }
            }
        }
    }
    return res;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    string selected;
    for(auto x:s) {
        selected += '0';
        end_str += '1';
    }
    cout << solve(0, 2*n-1, selected, 0) << endl;
    return 0;
}
