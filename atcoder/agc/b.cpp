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
    ll n,k;cin>>n>>k;
    ll p[n];rep(i,n){cin>>p[i];p[i]++;}
    BinaryIndexTree bit = BinaryIndexTree(n+5);
    ll cnt=1;
    rep(i,k){
        bit.add(p[i],1LL);
        if(i>0){
            if(p[i]>p[i-1]){
                cnt++;
            }
            else{
                cnt=1;
            }
        }
    }
    ll res = 1;
    bool flg = cnt==k;
    repr(i,k,n){
        bit.add(p[i-k],-1LL);
        bit.add(p[i],1LL);
        if(p[i]>p[i-1]){
            cnt = min(cnt+1,k);
        }else{cnt=1;}
        if(!flg&&cnt==k){res++;flg=true;}
        else if(cnt!=k&&(bit.sum(p[i])!=k||bit.sum(p[i-k])!=0)){res++;}
        DEBUG{
            cout << cnt << " " << res <<endl;

        }
    }
    cout << res << endl;
    return 0;
}
