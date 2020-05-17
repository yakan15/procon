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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<string> s(n);
    map<char, ll> cnt;
    cnt['A'] = a;
    cnt['B'] = b;
    cnt['C'] = c;
    rep(i,n) {
        cin>>s[i];
    }
    vector<char> res;
    rep(i,n) {
        char c1 = s[i][0],c2 = s[i][1];
        if (cnt[c1]<=0 && cnt[c2]<=0) {
            cout << "No" << endl;
            return 0;
        }
        if (cnt[c1]>cnt[c2]) {
            cnt[c1]--;cnt[c2]++;
            res.push_back(c2);
        }
        else if (i<n-1&&cnt[c1]==cnt[c2]) {
            if(s[i+1][0] == c1 || s[i+1][1] == c1) {
                cnt[c1]++;cnt[c2]--;
                res.push_back(c1);
            }
            else {
                cnt[c1]--;cnt[c2]++;
                res.push_back(c2);
            }
        }
        else {
            cnt[c1]++;cnt[c2]--;
            res.push_back(c1);
        }
    }
    cout << "Yes" << endl;
    for(auto x:res) {
        cout << x << endl;
    }
    return 0;
}
