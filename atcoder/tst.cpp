#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct nt {
    ll time;
    ll node;
    ll money;
    nt(ll t, ll n, ll m) : time(t), node(n), money(m) {}
};

struct conNt {
    bool operator()(nt const &a, nt const &b) {
        return a.time > b.time;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    priority_queue<nt, vector<nt>, conNt> pq;
    cout <<" test " << endl;
    for(int i=0;i<5;i++) {
        pq.emplace(6-i,4LL,5LL);
    }
    while(!pq.empty()) {
        cout << pq.top().time << endl;
        pq.pop();
    }
    return 0;
}
