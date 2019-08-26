#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;cin>>h>>w;
    string s[h];
    int cnt[26]={};
    rep(i,h){
        cin>>s[i];
    }
    rep(i,h){
        rep(j,w){
            cnt[s[i][j]-'a']++;
        }
    }
    int c4 = (h/2*2)*(w/2*2)/4;
    int c2 = (h*w-c4*4)/2;
    int c1 = h*w-c2*2-c4*4;
    rep(i,26){
        while(cnt[i]>=4&&c4>0){
            cnt[i]-=4;
            c4--;
        }
        while(cnt[i]>=2&&c2>0){
            cnt[i]-=2;
            c2--;
        }
        while(cnt[i]>=1&&c1>0){
            cnt[i]-=1;
            c1--;
        }
    }
    rep(i,26){
        if(cnt[i]!=0){
            cout << "No" << endl;    
            return 0;
        }
    }
    if(c4!=0||c2!=0||c1!=0){
        cout << "No" << endl;    
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
