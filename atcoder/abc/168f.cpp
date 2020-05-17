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
    ll n,m;cin>>n>>m;
    vector<ll> a(n),b(n),c(n),d(m),e(m),f(m);
    set<ll> st;
    st.insert(0);
    ll lim = 1e+10;
    st.insert(lim);
    st.insert(-lim);
    rep(i,n) {
        cin>>a[i]>>b[i]>>c[i];
        st.insert(a[i]);
        st.insert(b[i]);
        st.insert(c[i]);
    }
    rep(i,m) {
        cin>>d[i]>>e[i]>>f[i];
        st.insert(d[i]);
        st.insert(e[i]);
        st.insert(f[i]);
    }
    map<ll,ll> comp;
    vector<ll> compinv(st.size(),0);
    ll num = 0;
    for(auto x:st) {
        comp[x] = num;
        compinv[num++] = x;
    }
    ll c_size = comp.size();

    bool mat[c_size][c_size][2] = {};
    rep(i,n) {
        ll y = comp[c[i]];
        repr(j,comp[a[i]],comp[b[i]]) {
            mat[j][y][0] = true;
        }
    }
    rep(i,m) {
        ll x = comp[d[i]];
        repr(j,comp[e[i]],comp[f[i]]) {
            mat[x][j][1] = true;
        }
    }
    queue<pair<ll,ll>> que;
    que.emplace(comp[0],comp[0]);
    ll res = 0;
    vector<vector<bool>> chk(c_size,vector<bool>(c_size,true));
    chk[comp[0]][comp[0]] = false;
    while(!que.empty()) {
        ll x = que.front().first;
        ll y = que.front().second;
        que.pop();
        res += (compinv[x+1]-compinv[x]) * (compinv[y+1]-compinv[y]);
        if (x==0||y==0||x==c_size-2||y==c_size-2) {
            cout << "INF" << endl;
            return 0;
        }
        if (!mat[x][y][0]&&chk[x][y-1]) {
            que.emplace(x,y-1);
            chk[x][y-1] = false;
        }
        if (!mat[x][y][1]&&chk[x-1][y]) {
            que.emplace(x-1,y);
            chk[x-1][y] = false;
        }
        if (!mat[x][y+1][0]&&chk[x][y+1]) {
            que.emplace(x,y+1);
            chk[x][y+1] = false;
        }
        if (!mat[x+1][y][1]&&chk[x+1][y]) {
            que.emplace(x+1,y);
            chk[x+1][y] = false;
        }
    }
    cout << res << endl;
    return 0;
}
