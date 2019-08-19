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
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    a--;b--;c--;d--;
    string s;cin>>s;
    bool rock=false;
    bool ok=true;
    for(int i=a;i<=b;i++){
        if(s[i]=='#'){
            if(rock){
               ok=false;
               break; 
            }
            rock=true;
        }else{
            rock=false;
        }
    }
    for(int i=c;i<=d;i++){
        if(s[i]=='#'){
            if(rock){
               ok=false;
               break; 
            }
            rock=true;
        }else{
            rock=false;
        }
    }
    if(a<b&&c>d){
        for(int i=b;i<=d;i++){
            if(s.substr(i-1,3)=="..."){
                break;
            }
            if(i==d){ok=false;}
        }
    }
    if(a>b&&c<d){
        for(int i=a;i<=c;i++){
            if(s.substr(i-1,3)=="..."){
                break;
            }
            if(i==d){ok=false;}
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
