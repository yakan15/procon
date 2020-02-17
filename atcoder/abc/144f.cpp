#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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
    vector<set<int>> nbs(n);
    vector<set<int>> parents(n);
    vector<pair<int,int>> cand;
    rep(i,m) {
        int s,t;cin>>s>>t;
        s--;t--;
        nbs[s].insert(t);
        parents[t].insert(s);
    }
    vector<vector<double>> memo(n,vector<double>(2,-1));
    memo[n-1][0] = memo[n-1][1] = 0;
    function<void(int)> rec = [&](int k) {
        if(k == n-1)return;
        for(auto x:nbs[k]) {
            if(memo[x][0] == -1) {
                rec(x);
            }
        }
        double tmp = 0, mn,mx=0;
        for(auto x:nbs[k]) {
            tmp += memo[x][0];
            chmax(mx,memo[x][0]);
        }
        memo[k][0] = tmp / nbs[k].size();
        mn = tmp;
        for(auto x:nbs[k]) {
            chmin(mn, tmp-memo[x][0]+memo[x][1]);
        }
        memo[k][1] = mn/nbs[k].size();
        if(nbs[k].size() > 1) {
            chmin(memo[k][1], (tmp-mx)/(nbs[k].size()-1));
        }
        memo[k][0]++;memo[k][1]++;
        return;
    };
    rec(0);
    DEBUG{
        rep(i,n)cout << memo[i][0] << " " << memo[i][1] <<endl;
    }
    printf("%.10lf\n",memo[0][1]);
    return 0;
}
