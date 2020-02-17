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
    ll n,m,l;cin>>n>>m>>l;
    ll lim = 1e+15;
    vector<vector<pair<ll,ll>>> mat(n, vector<pair<ll,ll>>(n, pair<ll,ll>(1e+15, 0)));
    vector<vector<ll>> d(n,vector<ll>(n,1e+15));
    vector<set<ll>> nbs(n);
    rep(i,n) {
        mat[i][i].first = 0;
        d[i][i] = 0;
    }
    rep(i,m) {
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        if(c<=l) {
            d[a][b] = c;
            d[b][a] = c;
            nbs[a].insert(b);
            nbs[b].insert(a);
            // mat[a][b].first = mat[b][a].first = 0;
            // mat[a][b].second = mat[b][a].second = c;
        }
    }
    ll q;cin>>q;
    vector<ll> s(q), t(q);
    rep(i,q) {
        cin>>s[i]>>t[i];
        s[i]--;t[i]--;
    }
    
    rep(i,n) {
        vector<bool> flg(n,false);
        priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> pq;
        pq.emplace(0, 0, i); 
        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            ll now = get<2>(tmp), cnt= get<0>(tmp), dist = get<1>(tmp);
            DEBUG{
                printf("now: %lld, cnt: %lld, dist: %lld\n", now,cnt,dist);
            }
            if (flg[now]) continue;
            for(auto x:nbs[now]) {
                if (flg[x]) continue;
                ll _cnt, _dist;
                if(dist + d[now][x] <= l) {
                    _cnt = cnt;
                    _dist = dist + d[now][x];
                }else if(d[now][x] <= l) {
                    _cnt = cnt+1;
                    _dist = d[now][x];
                }
                if(_cnt < mat[i][x].first || _cnt == mat[i][x].first && _dist < mat[i][x].second) {
                    mat[i][x].first = _cnt;
                    mat[i][x].second = _dist;
                    pq.emplace(_cnt, _dist, x);
                }
            }
            flg[now] = true; 
        }
        DEBUG{
            cout << endl;
        }
    }
    rep(i,q) {
        cout << (mat[s[i]][t[i]].first == ll(1e+15) ? -1 : mat[s[i]][t[i]].first)  << endl;
    }
    return 0;
}
