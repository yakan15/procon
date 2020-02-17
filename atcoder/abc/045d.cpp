#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
int main(void) {
    set<pair<int, int>> st,checked;
    ll h,w,n;
    cin>>h>>w>>n;
    rep(i,n){
        int a,b;cin>>a>>b;
        a--;b--;
        st.emplace(a,b);
    }
    vector<ll> count(10,0);
    function<int(int,int)> check = [&](int x,int y){
        if(x<2||y<2||x>=h||y>=w){return -1;}
        int cnt = 0;
        repr(i,-2,1){
            repr(j,-2,1){
                if(st.find(pair<int, int>(x+i,y+j))!=st.end()){
                    cnt++;
                }
            }
        }
        DEBUG{
            printf("cnt: %d\n",cnt);;
        }
        return cnt;
    };
    for(auto x:st){
        repr(i,-2,3){
            repr(j,-2,3){
                if(checked.find(pair<int, int>(x.first+i,x.second+j))==checked.end()){
                    int tmp = check(x.first+i,x.second+j);
                    if(tmp!=-1){
                        count[tmp]++;
                    }
                    checked.emplace(x.first+i,x.second+j);
                }
            }
        }
    }
    ll res0 = (h-2)*(w-2);
    repr(i,1,10){
        res0 -= count[i];
    }
    cout << res0 << endl;
    repr(i,1,10){
        cout << count[i] << endl;
    }
    return 0;
}
