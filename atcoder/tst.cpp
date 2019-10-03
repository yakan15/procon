#include <bits/stdc++.h>
using namespace std;


int char_to_idx(char c){
    return (c < 'a' ? c-'A' : c-'a'+26);
}

char itoc(int i){
    return char(i<26 ? i+'A' : i-26+'a');
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    function<int(int)> tst = [&](int x){
        if(x==100000)return 0;
        return tst(x+1) + 1;
    };
    cout << tst(0) << endl;
}
