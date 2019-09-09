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
    int b[n+1];
    repr(i,1,n){
        cin>>b[i];
    }
    b[n]=b[n-1];
    b[0]=b[1];
    int res = b[0];
    repr(i,1,n){
        if(b[i]<b[i+1]){
            res += b[i];
        }else{
            res += min(b[i],b[i+1]);
        }
    }
    cout << res << endl;
    return 0;
}
