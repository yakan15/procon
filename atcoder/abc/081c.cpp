#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,k;
    cin >> n >> k;
    vector<int> a(n,0);
    int tmp;
    rep(i,n){
        cin >> tmp;
        a[tmp-1]++;
    }
    sort(a.begin(),a.end(),greater<int>());
    int res=0;
    rep(i,k){
        res += a[i];
    }
    cout << n-res << endl;
    return 0;
}