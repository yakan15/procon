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
    vector<ll> a(n),b(n);
    vector<pair<ll,ll>> pa,pb;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)pa.emplace_back(a[i],i);
    rep(i,n)pb.emplace_back(b[i],i);
    DEBUG{
        rep(i,n){
        printf("pa : %lld, pb: %lld\n", pa.at(i).first, pb.at(i).first);

        }
    }

    vector<ll> idxa(n,0), idxb(n,0);
    sort(begin(pa), end(pa));
    sort(begin(pb), end(pb));
    rep(i,n) idxa[pa[i].second] = i;
    rep(i,n) idxb[pb[i].second] = i;
    rep(i,n) {
        DEBUG{
            printf("pa : %lld, pb: %lld\n", pa.at(i).first, pb.at(i).first);
            printf("pa : %lld, pb: %lld\n", pa.at(i).second, pb.at(i).second);
        }
        if (pa[i].first > pb[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,n) {
        if (pa[i].second == pb[i].second) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    ll chable_cur = 0;
    rep(i,n) {
        if (a[pb[i].second] <= b[pb[i].second] && idxa[pb[i].second] >= i) {
            cout << "Yes" << endl;
            return 0;
        }
        if (idxa[pb[i].second] <= pb[i].second && idxa[pb[i].second] >= chable_cur && a[pb[i].second] <= b[pb[i].second]) {
            cout << "Yes" << endl;
            return 0;
        } 
        if (i < n && pb[i].first < pa[i+1].first) {
            chable_cur = i+1;
        } else {
            cout << "Yes" << endl;
        }
        if (a[pa[i].second] <= b[pa[i].second] && pa[idxb[pa[i].second]].first <= pb[i].first) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
