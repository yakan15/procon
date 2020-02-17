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
    ll n;cin>>n;
    vector<ll> T(n), A(n);
    rep(i,n){
        cin>>T[i]>>A[i];
    }
    ll t = T[0], a = A[0];
    repr(i, 1, n){
        DEBUG{
            printf("t: %lld, a: %lld\n", t,a);
        }
        if(T[i] == A[i]) {
            chmax(t, a);
            chmax(a, t);
            continue;
        }
        if(t % T[i] == 0 && a % A[i] == 0 && t / T[i] == a / A[i]) {
            DEBUG{
                printf("continue\n");
            }
            continue;
        }
        if(T[i] < A[i]) {
            if(t % T[i] != 0){
                t = (t / T[i] + 1) * T[i];
            }
            if(!chmax(a, t / T[i] * A[i])){
                if(a % A[i] != 0){
                    a = (a / A[i] + 1) * A[i];
                }
                t = a / A[i] * T[i];
            }
        } else {
            if(a % A[i] != 0){
                a = (a / A[i] + 1) * A[i];
            }
            DEBUG{
                printf("a: %lld\n", a);
            }
            if(!chmax(t, a / A[i] * T[i])){
                if(t % T[i] != 0){
                    t = (t / T[i] + 1) * T[i];
                }
                a = t / T[i] * A[i];
            }

        }
    }
    DEBUG{
        printf("t: %lld, a: %lld\n", t,a);
    }
    cout << a + t << endl;
    return 0;
}
