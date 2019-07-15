#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

bool is_prime[100005]={};

void check_prime(void){
    rep(i,100005)is_prime[i]=true;
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2;i<100005;i++){
        if(!is_prime[i])continue;
        for(int j=2;i*j<100005;j++)is_prime[i*j]=false;
    }
}

int main(void) {
    ll q;
    cin >> q;
    ll lr[q][2];
    ll sum[100006]={};
    check_prime();
    rep(i,q){
        cin >> lr[i][0] >> lr[i][1];
    }
    DEBUG{
        cout << is_prime[2] << endl;
        cout << is_prime[3] << endl;
    }
    rep(i,100006){
        if(i==0)continue;
        sum[i]=sum[i-1];
        if(i%2&&is_prime[i]&&is_prime[(i+1)/2])sum[i]++;
    }
    rep(i,q){
        cout << sum[lr[i][1]]-sum[lr[i][0]-1] << endl;
    }
    return 0;
}
