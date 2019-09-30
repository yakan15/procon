#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    vector<ll> res(n);
    res[0]=2;
    ll now = 3;
    ll sum = 2;
    if(n==3){
        printf("2 5 63\n");
        return 0;
    }
    repr(i,1,n-1){
        while(!(now%2==0||now%3==0)){
            now++;
        }
        res[i]= now;
        sum += now;
        DEBUG{
            printf("%lld\n",now);
        }
        now++;
    }
    DEBUG{
        cout << "sum: " << sum << endl;
    }
    int odd = res[n-2]%2;
    if((sum%6)%2==0){
        if(sum%6==2){
            res[n-1]=29998;
        }else if(sum%6==0){
            res[n-1]=30000;
        }else if(odd){
            res[n-2]+=5;
            res[n-1]=30000;
        }else{
            res[n-2]+=2;
            res[n-1]=30000;
        }
    }else if(sum%6==3){
        res[n-1]=29997;
    }else if(sum%6==5){
        if(odd){
            res[n-2]++;
            res[n-1]=30000;
        }else{
            res[n-2]+=4;
            res[n-1]=29997;
        }
    }else{
        if(odd){
            res[n-2]+=5;
            res[n-1]=30000;
        }else{
            res[n-2]+=2;
            res[n-1]=29997;
        }
    }
    rep(i,n){
        cout << res[i];
        cout << (i==n-1 ? "\n" : " ");
    }
    return 0;
}
