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
    ll N;
    cin >> N;
    ll A[N];
    ll sum[N+1]={};
    ll xorsum[N+1]={};
    rep(i,N){
        cin >> A[i];
        sum[i+1]=sum[i]+A[i];
        xorsum[i+1]=xorsum[i]^A[i];
    }
    DEBUG{
        rep(i,N+1){
            cout << "sum : " << sum[i] << endl;
            cout << "xorsum : " << xorsum[i] << endl;
        }
    }
    ll from=1,to=1;
    ll res=0;
    while(from<=N){
        while(sum[to]-sum[from-1]==(xorsum[to]^xorsum[from-1])&&to<=N)to++;
        to--;
        DEBUG{
            printf("from : %lld, to: %lld\n", from, to);
        }
        res += to-from+1;
        from++;
    }
    cout << res << endl;
    return 0;
}
