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

// 参考 https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid > 
class SegmentTree{
    using F = function< Monoid(Monoid, Monoid) >;
    public:
        SegmentTree(int n, const F f, const Monoid &initial) : f(f), initial(initial) {
           _size = 1; 
           while(_size < n){ _size <<= 1;}
           seg.assign(2 * _size, initial);
        }

        void set(int k, const Monoid &x) {
            seg.at(k + _size) = x;
        }

        void build() {
            for(int k = _size - 1; k > 0; k--) {
                seg.at(k) = f(seg.at(2 * k), seg.at(2 * k + 1));
            }
        }

        void update(int k, const Monoid &x) {
            k += _size;
            seg.at(k) = x;
            while(k >>= 1){
                seg.at(k) = f(seg.at(2 * k), seg.at(2 * k + 1));
            }
        }

        Monoid query(int a, int b){
            Monoid L = initial, R = initial;
            for(a += _size, b += _size; a < b; a>>= 1, b >>= 1) {
                if(a & 1) L = f(L, seg.at(a++));
                if(b & 1) R = f(seg.at(--b), R);
            }
            return f(L, R);
        }

        Monoid operator[](const int &k) const {
            return seg.at(k + _size);
        }

    private:
        int _size;
        vector< Monoid > seg;
        const F f;
        const Monoid initial;
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}
