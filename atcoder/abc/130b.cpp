#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,x;
    cin >> n >> x;
    vector<int> l;
    int ball=0;
    int res=1;
    rep(i,n){
        int tmp;
        cin >> tmp;
        ball += tmp;
        if(ball<=x)res++;
    }
    cout << res << endl;
    return 0;
}
