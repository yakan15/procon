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
    int n,q;
    string s;
    cin>>n>>s>>q;
    vector<set<int>> idxes(26, set<int>({1<<30}));
    rep(i,s.size()) {
        idxes[s[i]-'a'].insert(i);
    }
    rep(i,q) {
        int num;cin>>num;
        if (num==1) {
            int idx;cin>>idx;
            char c;cin>>c;
            idxes[s[--idx]-'a'].erase(idx);
            s[idx] = c;
            idxes[c-'a'].insert(idx);
        }
        else {
            int l,r;cin>>l>>r;
            l--;r--;
            int cnt = 0;
            rep(i,26) {
                if (idxes[i].empty())continue;
                auto from = *idxes[i].lower_bound(l);
                if(from<=r) cnt++;
            }
            cout << cnt << endl;
        }
    } 
    return 0;
}
