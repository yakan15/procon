#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n;
    cin>>n;
    int lst[n];
    rep(i,n)cin>>lst[i];
    rep(i,n)lst[i]--;
    int res=0;
    rep(i,n-1){
        if(lst[i]==i){
            swap(lst[i],lst[i+1]);
            res++;
        }
    }
    if(lst[n-1]==n-1){
        res++;
    }
    cout << res << endl;
    return 0;
}
