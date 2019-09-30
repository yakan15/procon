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
    ll n,k;cin>>n>>k;
    vector<ll> a(n),b(n);
    rep(i,n){cin>>a[i];}
    rep(i,n){cin>>b[i];}
    vector<pair<ll,ll>> diffs;
    ll sum = n*(n+1)/2;
    rep(i,n){
        diffs.push_back(make_pair(b[i]-a[i],i));
    }
    sort(begin(diffs),end(diffs), greater<pair<ll,ll>>());
    vector<int> chk(n+1,1);
    ll cnt=n;
    ll cur=0;
    while(cnt>k&&diffs[cur].first>0){
        assert(cur<n);
        int from = a[diffs[cur].second],to = b[diffs[cur].second];
        ll diff = diffs[cur].first;
        sum += diff;
        if(chk[from]==1){cnt--;}
        if(chk[to]==0){cnt++;}
        chk[from]--;chk[to]++;
        cur++;
    }
    while(cnt==k&&diffs[cur].first>0){
        int from = a[diffs[cur].second],to = b[diffs[cur].second];
        if(chk[from]==1&&chk[to]==0){
            chk[from]--;chk[to]++;
            sum += diffs[cur].first;
        }
        cur++;
    }
    cout << sum << endl;
    return 0;
}
