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
    int n,m;cin>>n>>m;
    vector<vector<int>> nbs(n);
    vector<pair<int,int>> cand;
    rep(i,m) {
        int s,t;cin>>s>>t;
        s--;t--;
        nbs[s].push_back(t);
    }
    int xx=0,yy=0;
    vector<double> memo(n,-1);
    function<double(int)> rec = [&](int k) {
        double mx = 0;
        double res = 0;
        if(k == n-1)return memo[k] = 0.0;
        if(memo[k] != -1) return memo[k];
        bool flg = false;
        for(auto x:nbs[k]) {
            if (xx==k&&yy==x)flg = true;
        }
        for(auto x:nbs[k]) {
            if(xx==k&&yy==x) {continue;}

            if(memo[x] == -1)rec(x);
        }
        for(auto x:nbs[k]) {
            if(xx==k&&yy==x) {
                continue;
            }
            double tmp = memo[x];
            chmax(mx,tmp);
            res += tmp * 1.0 / (nbs[k].size() - int(flg));
        }
        res++;
        return memo[k] = res;
    };
    rec(0);
    rep(i,n) {
        if(nbs[i].size() > 1) {
            double mn = 1e+12;
            int to;
            for(auto x:nbs[i]) {
                if(chmin(mn, memo[i]-memo[x])) {
                    to = x;
                }
            }

            cand.emplace_back(i, to);
        }
    }
    double res = memo[0];
    DEBUG{
        for(auto x:memo) cout << x << " ";
        cout << endl;
    }
    for(auto x:cand) {
        xx=x.first;yy=x.second;
        rep(i,n) {
            memo[i] = -1;
        }
        chmin(res, rec(0));
    }
    printf("%.10lf\n",res);
    return 0;
}
