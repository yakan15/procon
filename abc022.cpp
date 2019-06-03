#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;


int main(void){
    int n;
    vector<int> v;
    int tmp;
    cin >> n;
    rep(i,n){
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> csum;
    rep(i,n){
        if(i==0){
            csum.push_back(abs(v[i]));
        }else{
            csum.push_back(csum[i-1]+abs(v[i-1]-v[i]));
        }
    }
    rep(i,n){
        if(i==0){
            cout << csum[n-1]-csum[1]+abs(v[1])+abs(v[n-1]) << endl;;
        }else if(i==n-1){
            cout << csum[n-2]+abs(v[n-2]) << endl;
        }else{
            cout << csum[n-1]-csum[i+1]+csum[i-1]+abs(v[i-1]-v[i+1])+abs(v[n-1]) << endl;
        }
    }
    return 0;
}