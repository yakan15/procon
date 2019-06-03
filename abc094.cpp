#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;


int main(void){
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    rep(i,n){
        pair<int, int> tmp;
        cin >> tmp.first;
        tmp.second = i;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int med1 = v.at((n-2)/2).first;
    int med2 = v.at((n-2)/2+1).first;
    vector<pair<int, int> > rank;
    rep(i,n){
        pair<int, int> tmp;
        tmp.first = v.at(i).second;
        tmp.second = i;
        rank.push_back(tmp);
    }
    sort(rank.begin(),rank.end());
    rep(i,n){
        if(rank.at(i).second>(n-2)/2){
            cout << med1 << endl;
        }else{
            cout << med2 << endl;
        }
    }
    return 0;
}