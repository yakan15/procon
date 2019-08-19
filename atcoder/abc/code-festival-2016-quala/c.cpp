#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int change_num(char from, char to){
    if(from == to){
        return 0;
    }
    return int(to + 26 - from);
}

char after_alphabet(char from, int num){
    return (from - 'a' + num)% 26 + 'a';
}

int main(void) {
    string s;cin>>s;
    int k;cin>>k;
    int cur=0;
    int n = s.size();
    while(k>0&&cur<n){
        char alphabet = s.at(cur);
        if(cur==n-1){
            s.at(cur) = after_alphabet(s.at(cur), k);
        }else{
            int num = change_num(s.at(cur), 'a');
            if(num<=k){
                s.at(cur) = 'a';
                k -= num;
            }
        }
        cur++;
    }
    cout << s << endl;
    return 0;
}
