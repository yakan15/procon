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

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> cnt(n+1,0);
    vector<int> a(n+1);
    repr(i,1,n+1){cin>>a.at(i);}
    repr(i,1,n+1){
        cnt[a[i]]=cnt[a.at(i)-1]+1;
    }
    int res = 0;
    rep(i,n+1){res = max(res,cnt[i]);}
    cout << n-res << endl;
    return 0;
}
