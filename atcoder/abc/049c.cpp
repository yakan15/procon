#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    string s;
    cin >> s;
    int n=s.size();
    string dream="dream",dreamer="dreamer",erase="erase",eraser="eraser";
    int cur=n-1;
    while(cur>0){
        if(cur-5>=0&&s.substr(cur-5,6)=="eraser")cur-=6;
        else if(cur-4>=0&&s.substr(cur-4,5)=="erase")cur-=5;
        else if(cur-6>=0&&s.substr(cur-6,7)=="dreamer")cur-=7;
        else if(cur-4>=0&&s.substr(cur-4,5)=="dream")cur-=5;
        else break;
    } 
    if(cur==-1)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
