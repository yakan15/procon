#include <bits/stdc++.h>
using namespace std;

int bit_count(int bits){
    int n = 0;
    for(;bits!=0;bits&=bits-1){
        n++;
    }
    return n;
}

int main(void) {
    int N,M;
    cin >> N >> M;
    vector<int> bits;
    vector<int> p;
    for (int i=0;i<M;i++){
        int k;
        cin >> k;
        int value = 0;
        for (int j=0;j<k;j++){
            int s;
            cin >> s;
            value += 1*pow(2,s-1);
        }
        bits.push_back(value);
    }
    for (int i=0;i<M;i++){
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    int count=0;
    for (int i=0;i<pow(2,N);i++){
        bool flg = true;
        for (int j=0;j<M&&flg==true;j++){
            if (bit_count(bits.at(j) & i) % 2 != p.at(j)){
                flg=false;
            }
        }
        if(flg)count++;
    }
    cout << count <<endl;
    return 0;
}