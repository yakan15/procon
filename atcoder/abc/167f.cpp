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
const ll MOD = 998244353;
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
    ll n;
    cin>>n;
    vector<string> s(n);
    vector<pair<ll,ll>> xup, xdown;
    ll minuscnt = 0;
    rep(i,n) {
        cin>>s[i]; 
        ll cnt = 0;
        while(s[i][cnt]==')'&&cnt<s[i].size()) {
            cnt++;
        }
        ll cnt2 = 0;
        for(auto a:s[i]) {
            cnt2 += (a=='(' ? 1 : -1);
        }
        if (cnt2 >=0) {
            xup.emplace_back(cnt, cnt2);
        }
        else {
            minuscnt -= cnt2;
            ll cnt = 0;
            while(s[i][s[i].size()-1-cnt]=='('&&cnt<s[i].size()) {
                cnt++;
            }
            xdown.emplace_back(cnt, -cnt2);
        }
    }

    sort(begin(xup), end(xup));
    sort(begin(xdown), end(xdown));
    ll now = 0;

    for(auto up:xup) {
        if (up.first > now) {
            cout << "No" << endl;
            return 0;
        }
        now += up.second;
    }
    ll tmp = now;
    now=0;
    for(auto up:xdown) {
        if (up.first > now) {
            cout << "No" << endl;
            return 0;
        }
        now += up.second;
    }
    if (tmp == now) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
