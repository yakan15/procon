#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

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

// have not verified
int main(void) {
    BinaryIndexTree bit(5);
    cout << bit.sum(3) << endl;
    bit.add(2,1LL<<24);
    bit.add(3,1);
    bit.add(4,5);
    rep(i,bit.size()){
        cout << bit.sum(i) << endl;
    }
    return 0;
}
