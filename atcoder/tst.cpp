#include <bits/stdc++.h>
using namespace std;


int char_to_idx(char c){
    return (c < 'a' ? c-'A' : c-'a'+26);
}

char itoc(int i){
    return char(i<26 ? i+'A' : i-26+'a');
}

template<class T> inline void printb(T a) {
    int cnt = sizeof(T)*8-1;
    printf("%d\n",cnt);
    bool flg = false;
    while(cnt>=0){
        if(!flg&&a>>cnt&1){
            flg = true;
        }
        if(flg){
            cout << (a>>cnt&1);
        }
        cnt--;
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    printb(20);
}
