#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
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
    ll n,m;
    cin>>n>>m;
    if (n%2==1) {
        ll sm = n/2, lg = sm+1;
        rep(i,m) {
            cout << sm << " " << lg << endl;
            sm--;lg++;
        }
    }
    else {
        ll ue = n / 2, sita = ue;
        ll lg,sm, cnt;
        if (n % 4 == 0) {
            sm = sita + 2; lg = n;
            cnt = ue / 2 - 1;
        }
        else {
            ue -= 1;
            sm = sita + 1; lg = n;
            cnt = ue / 2;
        }
        while(m>0) {
            if (cnt == 0) {
                if (n % 4 == 0) {
                    sm = 1;
                    lg = sita;
                }
                else {
                    sm = 1;
                    lg = sita-1;
                }
            }
            cout << sm << " " << lg << endl;
            sm++;lg--;cnt--;
            m--;
        }
    }
    return 0;
}
