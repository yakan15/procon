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
    cin >>n;
    int t[n],v[n];
    rep(i,n)cin>>t[i];
    rep(i,n)cin>>v[i];
    int minutes_=0;
    rep(i,n)minutes_+=t[i];
    int speed[minutes_+1][2]={};
    int sp_now=0,time=0;
    rep(i,n){
        rep(j,t[i]){
            if(sp_now<v[i]){
                sp_now++;
            }else{
                sp_now=v[i];
            }
            time++;
            speed[time][0]=sp_now;
        }
    }
    sp_now=0;
    time = minutes_;
    for(int i=n-1;i>=0;i--){
        rep(j,t[i]){
            if(sp_now<v[i]){
                sp_now++;
            }else{
                sp_now=v[i];
            }
            time--;
            speed[time][1]=sp_now;
        }
    }
    long double res=0;
    int cnt_cross=0;
    sp_now=0;
    int sp_next=0;
    rep(i,minutes_+1){
        if(i==0)continue;
        sp_now=sp_next;
        sp_next=min(speed[i][0],speed[i][1]);
        res+=(sp_now+sp_next);
        if(speed[i-1][0]<speed[i-1][1]&&speed[i][0]>speed[i][1])cnt_cross++;
    }
    res /= 2.0;
    res += cnt_cross/4.0;
    printf("%Lf\n",res);
    return 0;
}
