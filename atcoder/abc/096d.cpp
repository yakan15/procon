#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

priority_queue<ll, vector<ll>, greater<ll> > primes;
bool is_prime[55555*5+1]={};

void make_primes(ll n){
    rep(i,n+1)is_prime[i]=true;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            if(i<55555)primes.push(i);
            ll cnt=2;
            while(i*cnt<=n){
                is_prime[cnt*i]=false;
                cnt++;
            }
        }
    }    
}

int main(void) {
    ll n;
    cin >> n;
    make_primes(55555*5);
    vector<ll> res;
    DEBUG{
        cout << primes.top() << endl;
    }
    while(res.size()<n){
        if(primes.top()%10==1)res.push_back(primes.top());
        primes.pop();
    }
    rep(i,res.size()){
        printf("%lld",res[i]);
        if(i!=res.size()-1)printf(" ");
    }
    printf("\n");
    return 0;
}
