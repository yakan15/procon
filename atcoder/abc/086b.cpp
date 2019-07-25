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
    string a,b;
    set<int> aa;
    rep(i,1000){
        aa.insert(i*i);
    }
    cin>>a>>b;
    a+=b;
    if(aa.find(stoi(a))!=aa.end())cout << "Yes" << endl;
    else cout <<"No"<<endl;
    return 0;
}
