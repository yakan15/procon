#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n;
    cin>>n;
    deque<int> que;
    rep(i,n){
        int tmp;cin>>tmp;
        if(i%2)que.push_back(tmp);
        else que.push_front(tmp);
    }
    rep(i,n){
        if(n%2){
            cout << que.front();
            que.pop_front();
        }else{
            cout << que.back();
            que.pop_back();
        }
        if(i==n-1)cout << endl;
        else cout << " ";
    }
    return 0;
}
