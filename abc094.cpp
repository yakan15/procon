#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

bool vcompare(const pair<int, int> f, const pair<int, int> l){
    return f.second > l.second;
}

// bool vcompare(const pair<int, int> f, const pair<int, int> l){
//     return f.first > l.first;
// }

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int> > x;
    rep(i,n){
        pair<int, int> tmp;
        cin >> tmp.second;
        tmp.first = i;
        x.push_back(tmp);// first 番号 second 数値
    } 
    sort(x.begin(), x.end(), vcompare);
    vector<pair<int, int> > place;
    rep(i,n){
        pair<int, int> tmp;
        tmp.first=i;
        tmp.second=x.at(i).first;
        place.push_back(tmp);
    }
    sort(place.begin(),place.end(),vcompare);


    int med1 = x.at((n-2)/2).second;
    int med2 = x.at((n-2)/2+1).second;
    // cout << med1 << " " << med2 << endl;
    rep(i,n){
        // cout << "at " << place.at(i).first << endl;
        if(place.at(i).first>(n-2)/2)cout << med1 << endl;
        else cout << med2 << endl;
    }
    return 0;
}