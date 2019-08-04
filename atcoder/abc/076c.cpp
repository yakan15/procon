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
    string s,t;
    cin>>s>>t;
    int cur=0;
    int t_size=t.size(),s_size=s.size();
    bool ok=false;
    int from=0;
    while(cur+t_size<=s_size){
        DEBUG{cout << cur<< endl;}
        bool flg=true;
        for(int i=0;i+cur<s_size&&i<t_size;i++){
            if(!(s[cur+i]=='?'||s[cur+i]==t[i])){
                flg=false;
                break;
            }
        }
        if(flg){
            ok=true;
            from=cur;
        }
        cur++;
    }
    if(!ok){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    s.replace(from,t_size,t);
    replace(s.begin(),s.end(),'?','a');
    cout << s << endl;
    return 0;
}
