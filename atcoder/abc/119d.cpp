#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ll a,b,q;
    cin >> a >> b >> q;
    vector<ll> va(a,0),vb(b,0),vq(q,0);
    rep(i,a){
        cin >> va[i];
    }
    rep(i,b){
        cin >> vb[i];
    }
    rep(i,q){
        cin >> vq[i];
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    rep(i,q){
        auto ap2 = lower_bound(va.begin(),va.end(),vq[i]);
        auto bp2 = lower_bound(vb.begin(), vb.end(),vq[i]);
        if(ap2==va.end()){ap2-=1;}
        if(bp2==vb.end()){bp2-=1;}
        vector<ll>::iterator ap=ap2-1,bp=bp2-1;
        if(a==1){ap++;}
        if(b==1){bp++;}
        if(a!=1&&*ap2==va[0]){ap+=2;}
        if(b!=1&&*bp2==vb[0]){bp+=2;}
        DEBUG{
            cout << "a1 " << *ap << " a2 " << *ap2 << endl;
            cout << "b1 " << *bp << " b2 " << *bp2 << endl;
        }
        ll xq = vq[i];
        ll res=0;
        res = abs(xq-*ap2)+abs(*ap2-*bp2);
        res = min(res,abs(xq-*ap2)+abs(*ap2-*bp));
        res = min(res,abs(xq-*ap)+abs(*ap-*bp2));
        res = min(res,abs(xq-*ap)+abs(*ap-*bp));
        res = min(res,abs(xq-*bp2)+abs(*bp2-*ap2));
        res = min(res,abs(xq-*bp2)+abs(*bp2-*ap));
        res = min(res,abs(xq-*bp)+abs(*bp-*ap2));
        res = min(res,abs(xq-*bp)+abs(*bp-*ap));
        cout << res << endl;
    }
    return 0;
}
