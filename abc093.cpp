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
    while(v.at(0)!=v.at(2)){
        if(v.at(0)>v.at(2)){
            v.at(1)++;
            v.at(2)++;
        }else if(v.at(1)==v.at(2)){
            v.at(0) +=2;
        }else{
            v.at(0)++;
            v.at(1)++;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}