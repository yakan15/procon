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
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    string s="";
    int cnt=0;
    while(n!=0){
        if(abs(n)%2)s="1"+s;
        else s="0"+s;
        n-=(abs(n)%2)*pow(-1,cnt);
        n/=2;
        DEBUG{
            cout << n << endl;
        }
        cnt++;
    }
    cout << s << endl;
    return 0;
}
