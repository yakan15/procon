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
    cin>>s;
    int n = s.size();
    int cnt[26]={};
    cnt[s[0]-'a']++;
    for(int i=1;i<n;i++){
       cnt[s[i]-'a']++;
       if(cnt[s[i]-'a']==2){
           printf("%d %d\n", i, i+1);
           return 0;
       } 
       cnt[s[i-1]-'a']--;
    }
    rep(i,26){
        cnt[i]=0;
    }
    cnt[s[0]-'a']++;cnt[s[1]-'a']++;
    for(int i=2;i<n;i++){
        cnt[s[i]-'a']++;
        if(cnt[s[i-2]-'a']>=2||cnt[s[i-1]-'a']>=2){
           printf("%d %d\n", i-1, i+1);
           return 0;
        }
        cnt[s[i-2]-'a']--;
    }
    printf("-1 -1\n");
    return 0;
}
