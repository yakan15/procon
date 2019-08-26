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
    int start=0; 
    double memo[1<<16];
    rep(i,1<<16){
        memo[i]=-1;
    }
    rep(i,n){
        int tmp;cin>>tmp;
        start += 1<<tmp;
    }
    function<double(int)> solve = [&](int bit){
        DEBUG{
            cout <<"bit : " << bit << endl;
        }
        if(memo[bit]!=-1){
            DEBUG{
                cout << "res : " << memo[bit] << endl;
            }
            return memo[bit];
        }
        if(bit==0){return 0.0;}
        int mask = 0b111;
        double res = DBL_MAX;
        rep(i,14){
            int focus = (bit>>i)&mask;
            DEBUG{
                cout << "focus : " << focus << endl;
            }
            double tmp = 0;
            if(focus==0){continue;}
            rep(j,3){
                if((bit>>i+j)&1){
                    tmp += solve(bit^(1<<i+j));
                }
            }
            if(__builtin_popcount(focus)==3){
                tmp /=3.0;
                tmp += 1;
            }else if(__builtin_popcount(focus)==2){
                tmp /=2;
                tmp += 1.5;
            }else{
                tmp /= 1;
                tmp += 3;
            }
            DEBUG{
                cout << "res : " << res << endl;
            }
            res = min(res, tmp);
        }
        return memo[bit] = res;
    };
    printf("%lf\n",solve(start));
    return 0;
}
