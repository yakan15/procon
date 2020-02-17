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
    vector<pair<ll,ll>> b(2,pair<ll,ll>(1,1e+9));
    vector<tuple<ll,ll,ll>> in;
    rep(i,n) {
        ll x,y;cin>>x>>y;
        
        in.push_back(make_tuple(y-x+1,x,y));
    }
    sort(begin(in), end(in));
    b[0].first = get<1>(in[0]);
    b[0].second = get<2>(in[0]);
    b[1].first = get<1>(in[n-1]);
    b[1].second = get<2>(in[n-1]);
    DEBUG{
        cout << "sz: " << in.size() << endl;
        cout << get<1>(in[0]) << endl; 
        rep(i,n)cout << get<1>(in[i]) << get<2>(in[i]) << endl;
    }
    repr(i,1,n-1) {
        DEBUG{
            cout << i << endl;
        }
        ll b0range_now = b[0].second - b[0].first + 1;
        ll b1range_now = b[1].second - b[1].first + 1;
        ll b0from = max(b[0].first, get<1>(in[i]));
        ll b0to = min(b[0].second, get<2>(in[i]));
        ll b1from = max(b[1].first, get<1>(in[i]));
        ll b1to = min(b[1].second, get<2>(in[i]));
        ll b0range = max(0LL, b0to-b0from+1);
        ll b1range = max(0LL, b1to-b1from+1);
        if(b0range==0||b1range==0) {
            DEBUG{
                cout << "ret" << endl;
            }
            cout << get<0>(in[n-1])+1 << endl;
            return 0;
        } else if(b0range_now == b0range ||
        b1range_now == b1range) {
            DEBUG{
                cout << "continue" << endl;
            }
            continue;
        } else if (b0range_now-b0range<=b1range_now-b1range) {
            b[0].first = b0from;
            b[0].second = b0to;
        } else {
            b[1].first = b1from;
            b[1].second = b1to;
        }
        DEBUG{
            cout << "aaa" << i << endl;
            rep(ii,2){
                cout << b[ii].first << " " << b[ii].second << endl;
            }
        }
    }
    ll res = b[0].second-b[0].first+1+
                b[1].second-b[1].first+1;
    cout << max(res,get<0>(in[n-1])+1) << endl;
    return 0;
}
