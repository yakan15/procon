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
    ll h,w;
    cin >> h >> w;
    if(h%3==0||w%3==0){
        cout << 0 << endl;
        return 0;
    }
    ll res = 1LL<<60;
    for(ll i=1;i<h-1;i++){
        ll tmp=res;
        ll maxx = max(i, (h-i)/2+(h-i)%2); 
        ll minx = min(i, (h-i)/2); 
        res = min(res, abs(maxx*w-minx*w));
    }
    DEBUG{cout << res << endl;}
    for(ll i=1;i<w-1;i++){
        ll maxx = max(i, (w-i)/2+(w-i)%2); 
        ll minx = min(i, (w-i)/2); 
        res = min(res, abs(maxx*h-minx*h));
    }
    DEBUG{cout << res << endl;}
    for(ll i=1;i<h;i++){
        ll maxx = max(i*w, (h-i)*(w/2+w%2)); 
        ll minx = min(i*w, (h-i)*(w/2)); 
        res = min(res, abs(maxx-minx));
    }
    DEBUG{cout << res << endl;}
    for(ll i=1;i<w;i++){
        ll maxx = max(i*h, (w-i)*(h/2+h%2)); 
        ll minx = min(i*h, (w-i)*(h/2)); 
        res = min(res, abs(maxx-minx));
    }
    // for(ll i=1;i<w;i++){
    //     res = min(res, abs(i*h-(h-i)*(h/2)));
    // }
    cout << res << endl;
    return 0;
}
