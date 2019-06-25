#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    string s,t;
    cin >> s>>t;
    unordered_map<char,int> ms,mt;
    int num=0;
    int n_s[s.size()],n_t[s.size()];
    rep(i,s.size()){
        if(ms.find(s[i])!=ms.end())n_s[i]=ms[s[i]];
        else{
            ms[s[i]]=num;
            n_s[i]=num;
            num++;
        }
    }
    num=0;
    rep(i,s.size()){
        if(mt.find(t[i])!=mt.end())n_t[i]=mt[t[i]];
        else{
            mt[t[i]]=num;
            n_t[i]=num;
            num++;
        }
    }
    rep(i,s.size()){
        if(n_s[i]!=n_t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
