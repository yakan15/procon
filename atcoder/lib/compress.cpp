#include <bits/stdc++.h>
using namespace std;

"""
Args :
    - raw (set<long long>) : 圧縮する前の座標の集合

Returns :
    - comp (map<long long, long long>) : 圧縮前→圧縮後の対応表
    - compinv (vector<long long>) : 圧縮後→圧縮前の対応表
"""
tuple<map<long long, long long>, vector<long long>> compress1d(set<long long> raw) {
    map<long long,long long> comp;
    vector<long long> compinv(raw.size(),0);
    long long num = 0;
    for(auto x:raw) {
        comp[x] = num;
        compinv[num++] = x;
    }
    return forward_as_tuple(comp, compinv);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    set<long long> x;
    x.insert(3);
    x.insert(5);
    x.insert(-1);
    map<long long, long long> comp;
    vector<long long> compinv;
    tie(comp, compinv) = compress1d(x);
    for (auto x:comp) {
        printf("%lld:%lld\n",x.first, x.second);
    }
    for(auto i=0;i<compinv.size();i++) {
        printf("%d:%lld\n",i,compinv[i]);
    }
    return 0;
}
