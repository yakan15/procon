#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n,t;
    cin >>n >> t;
    vector<int> c;
    rep(i,n){
        int tmpc,tmpt;
        cin >>tmpc >> tmpt;
        if(tmpt<=t)c.push_back(tmpc); 
    }
    if(c.size()==0){
        cout << "TLE" << endl;
        return 0;
    }
    sort(c.begin(), c.end());
    cout << c[0] << endl;
    return 0;
}
