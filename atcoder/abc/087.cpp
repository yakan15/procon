#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n;
    cin >> n;
    vector<int> v1, v2;
    int tmp;
    rep(i,n){
        cin >> tmp;
        v1.push_back(tmp);
    }
    rep(i,n){
        cin >> tmp;
        v2.push_back(tmp);
    }
    int res=0;
    int s;
    rep(i,n){
        s=0;
        rep(j,n){
            if(j<i)s += v1[j];
            else if(j==i)s += v1[j]+v2[j];
            else s+= v2[j];
        }
        res = max(res,s);
    }
    cout << res << endl;
    return 0;
}