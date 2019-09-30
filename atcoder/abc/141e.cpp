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
    ll n;cin>>n;
    string s;cin>>s;
    vector<vector<ll>> idxes(n,vector<ll>());
    // unordered_map<char,set<ll>> mp;
    // vector<vector<ll>> memo(n,vector<ll>(n,-1));
    rep(i,n){
        idxes[s[i]].push_back(i);
        // mp[s[i]].insert(i);
    }
    function<ll(ll,ll)> check = [&](ll cur, ll mx){
        ll result = 0;
        auto it = upper_bound(begin(idxes[s[cur]]), end(idxes[s[cur]]),cur+mx);
        // auto it = mp[s.at(cur)].upper_bound(cur+mx);
        // while(it!=mp[s[cur]].end()){
            while((it!=idxes[s[cur]].end())){
            ll from = *it;
            ll length = 1;
            while(cur+length<from&&from+length<n&&s[cur+length]==s[from+length]){
                length++;
            }
            chmax(result, length);
            it++;
        }
        DEBUG{
            printf("cur: %lld, res: %lld\n",cur,result);
        }
        return result;
    };
    ll res = 0;
    rep(i,n){
        if(res>=(n-i)/2){
            DEBUG{
                printf("out\n");
            }
            break;
        }
        chmax(res, check(i,res)); 

    }
    cout << res << endl;
    return 0;
}
