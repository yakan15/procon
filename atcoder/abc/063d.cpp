#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int n,a,b,k;
int h[100005];

bool check(int x){
    ll res=0;
    rep(i,n)res+=max(0, h[i]-b*x+a-b-1)/(a-b);
    return res<=x;
}

int binary_search(int a, int b){
    int from=a,to=b,mid;
    while(true){
        if(to-from<=1){
            if(check(from))return from;
            return to;
        }
        mid = (to+from)/2;
        if(check(mid))to=mid;
        else from=mid;
    }
}

int main(void) {
    cin>>n>>a>>b;
    int max_h=0;
    rep(i,n){
        cin>>h[i];
        max_h=max(max_h,h[i]);
    }
    k = max_h/b+1;
    cout << binary_search(1,k) << endl;
    return 0;
}
