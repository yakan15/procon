#include <bits/stdc++.h>

using namespace std;

int div9(int x){
    int i=1;
    for (;pow(9,i)<=x;i++){
    }
    // cout << pow(9,i-1)<<endl;
    if(i==1){return 0;}
    return pow(9,i-1);
}

int div6(int x){
    int i=1;
    for (;pow(6,i)<=x;i++){
    }
    // cout << i<<endl;
    if(i==1){return 0;}
    return pow(6,i-1);
}

int main(void){
    int N;
    cin >> N;
    int a,tmp1,tmp2;
    int count=0;
    a=N;
    while(true){
        cout << "a:" <<a<<endl;
        tmp1 = a-div9(a);
        tmp2 = a-div6(a);
        // printf("%d, %d\n", tmp1,tmp2);
        if(tmp1==tmp2){
            count+=tmp1;
            break;
        }
        a=min(tmp1,tmp2);
        count++;
    }
    cout << count <<endl;
}