#include <bits/stdc++.h>
#define repf(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define rep(i,n) repf((i),0,(n))
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
vector<ll> primes;
vector<ll> p_num(101,0);
void find_primes(ll n){
    DEBUG{cout << "find prime" << endl;}
    repf(i,1,n+1){
        if(i==1)continue;
        if(i==2){
            primes.push_back(2);
            continue;
        }
        bool flg=false;
        for(auto x:primes){
            if(i%x==0){
                flg=true;
                break;
            }
        }
        if(!flg)primes.push_back(i);
    }
}

int main(void) {
    cin >> n;
    find_primes(n/2);
    DEBUG{
        cout << "primes" << endl;
        for(auto x:primes)cout << x << endl;
        cout << "primes end" << endl;
    }
    for(auto x:primes){
        ll tmp=n,cnt=0;
        while(tmp!=0){
            cnt += tmp/x;
            tmp /= x;
        }
        p_num[x]=cnt;
    }
    ll res=0;
    int cnt74=0, cnt24=0, cnt14=0, cnt4=0, cnt2=0; 
    for(auto x:p_num){
        if(x>=74)cnt74++;
        if(x>=24)cnt24++;
        if(x>=14)cnt14++;
        if(x>=4)cnt4++;
        if(x>=2)cnt2++;
    }
    res += cnt74;
    if(cnt4>=2)res += cnt14*(cnt4-1);
    if(cnt2>=2)res += cnt24*(cnt2-1);
    if(cnt4>=2&&cnt2>=3)res += cnt4*(cnt4-1)*(cnt2-2)/2;
        // 5 5 3, 15 5, 75 1, 25 3,
    cout << res << endl;
    return 0;
}
