#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    string S;
    cin >> N >> S;
    int count=0;
    int res;
    for (int i=1;i<N;i++){
        if(S.at(i)=='E'){count++;}
    }
    res=count;
    for(int i=1;i<N;i++){
        if(S.at(i)=='E'){count--;}
        if(S.at(i-1)=='W'){count++;}
        if(count<=res){res=count;}
        // cout << "i: " << i <<" count: " << count <<endl;
    }
    cout << res <<endl;
    return 0;
}
