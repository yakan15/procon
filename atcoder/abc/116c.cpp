#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
int main(void) {
    cin >> n;
    ll h[n];
    rep(i,n){
        cin >> h[i];
    }
    bool flg=true;
    ll length[n]={};
    ll res=0;
    bool first;
    while(flg){
        flg=false;
        first=true;
        rep(i,n){
            if(length[i]==h[i]){
                first=true;
            }else{
                if(first){
                    first=false;
                    flg=true;
                    res++;
                }
                length[i]++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
