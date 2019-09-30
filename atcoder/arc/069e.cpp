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

class BinaryIndexTree{
    public:
        BinaryIndexTree(long long N) : n(N), data(n*2-1,0) {}
        long long sum(long long i){
            assert(i < n);
            long long s = 0;
            while(i > 0){
                s += data[i];
                i -= i & -i;
            }
            return s;
        } 
        long long add(long long i, long long x){
            assert(i < n);
            while(i <= n){
                data[i] += x;
                i += i & -i;
            }
        }
        long long size(void){
            return n;
        }
    private:
        long long n;
        vector<long long> data;
};


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    pair<ll,ll> a[n];
    rep(i,n){
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a,a+n,greater<pair<ll,ll>>());
    ll res[n+1]={};
    ll cnt = a[0].first;
    ll cur = 0;
    ll min_a = n;
    while(cur<n){
        while(cur<n&&cnt==a[cur].first){
            cur++;
        }
        chmin(min_a,a[cur-1].second);
        DEBUG{
            cout << "min_a: " << min_a << endl;
        }
        if(cur==n){
            res[min_a] += a[cur-1].first*cur;
        }else{
            res[min_a] += (a[cur-1].first-a[cur].first)*cur;
        }
        cnt = a[cur].first;
    }
    repr(i,1,n+1){
        cout << res[i] << endl;
    }
    return 0;
}
