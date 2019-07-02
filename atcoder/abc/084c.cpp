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
    cin >> n;
    int C[n-1],S[n-1],F[n-1];
    rep(i,n-1){
        cin >> C[i] >> S[i] >> F[i];
    }
    rep(i,n){
        int res=0;
        for(int j=i;j<n-1;j++){
            if(S[j]>res)res=S[j]+C[j];
            else if(res%F[j]==0)res+=C[j];
            else res+= F[j]-res%F[j]+C[j];
        }
        cout << res << endl;
    }
    return 0;
}
