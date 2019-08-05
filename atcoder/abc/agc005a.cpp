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
    string s;cin>>s;
    int cur=0;
    while(cur<s.size()){
        while(cur<s.size()&&s.substr(cur,2)=="ST"){
            s.erase(cur,2);
            cur = max(0,cur-1);
        }
        cur++;
    }
    cout << s.size() << endl;
    return 0;
}
