#include <bits/stdc++.h>
using namespace std;


int char_to_idx(char c){
    return (c < 'a' ? c-'A' : c-'a'+26);
}

char itoc(int i){
    return char(i<26 ? i+'A' : i-26+'a');
}

template<class T> inline void printb(T a) {
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c;
    a = stoi("06");
    cin>>b;
    cout << a <<" " << b<< endl;
}
