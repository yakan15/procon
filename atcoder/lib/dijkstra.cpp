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

template<typename T>
template<typename S>
vector<T> dijkstra(vector<S> &mat, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(mat.size(), INF);
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while(!que.empty()) {
        T cost;
        int idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) {continue;} 
        for(auto x : mat[idx]) {
            auto next_cost = 
        }
        
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}
