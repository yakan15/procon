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
    string s;
    cin >> s;
    int a[4];
    rep(i,4){
        a[i]=int(s[i]-'0');
    }
    rep(i,8){
        int tmp=a[0];
        rep(j,3){
            if(i>>j &1){
                tmp+=a[j+1];
            }else tmp-=a[j+1];
        }
        DEBUG{cout << "tmp : " << tmp << endl;}
        if(tmp==7){
            cout << a[0];
            rep(j,3){
                if(i>>j&1)cout << '+';
                else cout << '-';
                cout << a[j+1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    return 0;
}
