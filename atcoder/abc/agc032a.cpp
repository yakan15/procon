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
    cin>>n;
    vector<int> b(n,0);
    rep(i,n){
        cin>>b[i];
    }
    vector<int> res(n,0);
    int cnt=n-1;
    while(true){
        if(b.empty()){break;}
        int cur=b.size()-1;
        while(cur>=0&&b[cur]-1!=cur){
            cur--;
        }
        if(cur<0){break;}
        res[cnt]=b[cur];
        b.erase(b.begin()+cur);
        cnt--;
    }
    if(!b.empty()){cout << -1 << endl;}
    else{
        rep(i,n){
            cout << res[i] <<endl;
        }
    }
    return 0;
}
