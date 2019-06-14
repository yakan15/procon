#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n,0);
    int tmp,count=0;
    rep(i,n){
        cin >> tmp;
        if(tmp>n)count++;
        else a[tmp-1]++;
    }
    rep(i,n){
        if(a[i]==0)continue;
        else if(a[i]<i+1)count+=a[i];
        else if(a[i]>i+1)count+=a[i]-i-1;
    }
    cout << count << endl;
    return 0;

}