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
    int n,k;cin>>n>>k;
    int cnt = (n-1)*(n-2)/2;
    if(cnt<k){
        cout << -1 << endl;
        return 0;
    }
    vector<vector<bool> > chk(n,vector<bool>(n,false));
    rep(i,n){chk[i][i]=true;}
    vector<pair<int,int>> res;
    repr(i,1,n){
        res.emplace_back(0,i);
        chk[0][i]=chk[i][0]=true;
    }
    int source=1,target=2;
    while(cnt>k){
        if(!chk[source][target]){
            res.emplace_back(source, target);
            chk[source][target] = chk[target][source] = true;
            cnt--;
        }
        if(target==n-1){
            source++;
            target=0;
        }
        else{
            target++;
        }
    }
    cout << res.size() << endl;
    for(auto x:res){
        cout << x.first+1 << " " << x.second+1 << endl;
    }
    return 0;
}
