#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 998244353;

class BinaryIndexTree{
    public:
        BinaryIndexTree(int N) : n(N), data(n*2-1,0) {}
        int sum(int i){
            assert(i < n);
            int s = 0;
            while(i > 0){
                s += data[i];
                i -= i & -i;
            }
            return s;
        } 
        int reset(void){
            for(int i=0;i<n;i++){data[i] = 0;}
        }
        int add(int i, int x){
            assert(i < n);
            while(i <= n){
                data[i] += x;
                i += i & -i;
            }
        }
        int size(void){
            return n;
        }
    private:
        int n;
        vector<int> data;
};

int main(void) {
    ll n;
    cin>>n;
    int x[n],y[n];
    unordered_map<int, int> mpx,mpy;
    vector<pair<int,int> > point(n,pair<int,int>(0,0));
    rep(i,n){
        cin>>point[i].first>>point[i].second;
        x[i]=point[i].first;
        y[i]=point[i].second;
    }
    sort(x,x+i);
    sort(y,y+i);
    rep(i,n){
        mpx[x[i]]=i;
        mpy[y[i]]=i;
    }
    rep(i,n){
        point[i].first=mpx[point[i].first];
        point[i].second=mpy[point[i].second];
    }
    sort(point.begin(),point.end());
    int sg[n],gs[n],ss[n],gg[n];
    BinaryIndexTree bit(n);
    rep(i,n){
        ss[i]=bit.sum(point[i].second-1);
        sg[i]=bit.sum(n-1)-bit.sum(point[i].second-1);
        bit.add(point[i],second);
    }
    bit.reset();
    for(int i=n-1;i>=0;i--){
        gs[i]=bit.sum(point[i].second-1);
        gg[i]=bit.sum(n-1)-bit.sum(point[i].second-1);
        bit.add(point[i],second);
    }
    ll res = 0;
    // modpowが必要
    res += 
    return 0;
}
