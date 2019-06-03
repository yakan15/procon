#include <bits/stdc++.h>
using namespace std;

int div2(int x){
    int count=0;
    while(x % 2==0){
        count++;
        x = x / 2;
    }
    return count; 
}

int main(void) {
    int N;
    cin >> N;
    int count=0;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        count += div2(a);
    }
    cout << count << endl;


    return 0;
}