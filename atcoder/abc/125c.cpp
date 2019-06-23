#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n;
    cin >> n;
    // const auto igcd = gcd<int, int>;
    vector<int> a(n,0);
    rep(i,n){
        cin >> a[i];
    }
    int gcd_prev,gcd_now;
    gcd_now=a[0];
    gcd_prev=a[n-1];
    vector<int> up,down;
    rep(i,n){
       gcd_now=__gcd(gcd_now,a[i]);
       up.push_back(gcd_now);
    }
    rep(i,n){
        gcd_prev=__gcd(gcd_prev,a[n-1-i]);
        down.push_back(gcd_prev);
    }
    sort(down.begin(),down.end());
    DEBUG{
        cout << "up" << endl;
        rep(i,n){
            cout << up[i] << endl;
        }
        cout << "down" << endl;
        rep(i,n){
            cout << down[i] << endl;
        }
    }
    int res=0;
    rep(i,n){
        if(i==0)res=max(res,down[i+1]);
        else if(i==n-1)res=max(res,up[i-1]);
        else res=max(res,__gcd(up[i-1],down[i+1]));
    }
    cout << res << endl;
    return 0;
}
