#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
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

ll n,k;
vector<ll> pls,mns,mnp;
ll zeros = 0;
ll nz,np,nm;

bool chk1(ll now) {
    // minus
    ll cnt = 0;
    ll cur1 = pls.size()-1, cur2 = mns.size()-1;
    while(cur1>=0&&cur2>=0) {
        while(cur2>0&&pls[cur1]*mns[cur2]<now) {
            cur2--;
        }
        cnt += cur2;
        cur1--;
    }
    DEBUG{
        cout << nm-cnt << endl;
    }
    return k <= nm - cnt;
}

ll chk(vector<ll> v, ll now) {
    ll res = 0;
    ll l=v.size()-1,r=v.size()-1;
    while(r>0) {
        while(l>0&&v[l] *v[r] >=now) {
            l--; 
        }
        res += r-l;
        if (r!=l&&v[l]*v[r]<now) {res--;}
        r--;
        chmin(l,r);
    }
    return res;
}

bool chk2(ll now) {
    ll cnt = chk(pls, now);
    cnt += chk(mnp, now);
    DEBUG{
        cout << "cnt " << cnt << endl;
        cout << "np-k " << np-k << endl;
    }
    return cnt<np-k+1;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    rep(i,n) {
        ll tmp;cin>>tmp;
        if (tmp == 0) {zeros++;}
        else if (tmp > 0) {
            pls.push_back(tmp);
        }
        else {
            mns.push_back(tmp);
            mnp.push_back(tmp*-1); 
        }
    }
    sort(begin(pls), end(pls));
    sort(begin(mnp), end(mnp));
    sort(begin(mns), end(mns));
    ll npls = pls.size(),nmns = mns.size();
    nz = zeros * (npls + nmns) + zeros * (zeros-1)/2, np = npls * (npls-1) / 2 + nmns * (nmns-1)/2,nm = npls * nmns;
    DEBUG{
        cout << "nz:"<<nz<<" np:"<<np<<" nm:"<<nm<<endl;
    }
    ll flg = k > nz + nm ? 1: k>nm ? 0: -1;
    ll l=1e+18 * -1,r=1e+18;
    if (flg==1) {
        k -= nz + nm;
        l = 1;
    }
    else if (flg==-1) {
        r = -1;
    }
    DEBUG{
        cout << "flg:" << flg << endl;
        cout << "k:" << k << endl;
    }
    if (flg == 0) {
        cout << 0 << endl;
        return 0;
    }
    auto f = flg == 1 ? chk2 : chk1;
    while(r>l) {
        DEBUG{
            cout << "l:r = " << l<<":"<<r<<endl;
        }
        ll mid=(l+r)/2;
        if (f(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
        if (r-1==l) {
            if(f(l)) {
                l = r;
            }
            else {
                r = l;
            }
        }
    } 
    cout << l << endl;
    return 0;
}
