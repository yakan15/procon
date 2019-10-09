#include <bits/stdc++.h>
template<class T> inline void printb(T a) {
    if(a==0){
        cout << 0 << endl;
        return;
    }
    int cnt = sizeof(T)*8-1;
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
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}
