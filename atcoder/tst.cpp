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
    long long s = 1;
    for(long long i=1;i<=12;i++){
        s *= i;
    }
    cout << s << endl;
}
