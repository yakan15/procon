#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;


int main(void){
    int a;
    vector<int> v;

    rep(i,3){
        cin >> a;
        v.push_back(a);
    }
    int count=0;
    sort(v.begin(),v.end());
    int m = v.at(2)*3;
    int diff = m-v.at(0)-v.at(1)-v.at(2);
    if (diff%2==1){
        cout << (diff+3)/2 << endl;
    }else{
        cout << diff/2 << endl;
    }
}