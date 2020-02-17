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
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    vector<int> startidx;
    startidx.push_back(-1);
    vector<set<int>> idx(2*(1e+5)+10);
    int cnt = 0;
    int val = -1;
    rep(i,n){
        if (val != a[i]) {
            cnt = 1;
        } else {
            cnt++;
        }
        if(cnt<=2) {
            idx[a[i]].insert(i);
        }
    } 
    bool flg = true;
    int now = 0;
    while(now != 0 || flg) {
        flg = false;
        auto it = upper_bound(begin(idx[a[now]]), end(idx[a[now]]), now);
        if (it == idx[a[now]].end()) {
            startidx.push_back(now);
            now = *lower_bound(begin(idx[a[now]]), end(idx[a[now]]), 0);
        }
        else {
            now = *it;
        }
        now = (now+1) % n;
    }
    DEBUG{
        for(auto x: startidx) cout << x << " ";
        cout << endl;
    }
    ll start = (k-1) % (startidx.size());
    deque<int> que;
    vector<bool> flgs(4e+5,false);
    DEBUG{
        cout << "start: " << start << endl;
    }
    if(start != 0) {
        repr(i,startidx[start],n) {
            if(flgs[a[i]]) {
                while(que.back() != a[i]) {
                    flgs[que.back()] = false;
                    que.pop_back();
                }
                que.pop_back();
                flgs[a[i]] = false;
            }else {
                que.push_back(a[i]);
                flgs[a[i]] = true;
            }
        }
    }
    rep(i,n) {
        if(flgs[a[i]]) {
            while(que.back() != a[i]) {
                flgs[que.back()] = false;
                que.pop_back();
            }
            que.pop_back();
            flgs[a[i]] = false;
        }else {
            que.push_back(a[i]);
            flgs[a[i]] = true;
        }
    }
    while(!que.empty()) {
        cout << que.front();
        que.pop_front();
        cout << (que.empty() ? "\n" : " ");
    }
    return 0;
}
