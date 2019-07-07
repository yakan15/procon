#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=true;
// const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int cntx=0,cnty=0,cnt=0;
    vector<int> dx,dy;
    int first_t=0;
    rep(i,s.size()){
        if(s[i]=='F'){
            if(cnt&1)cnty++;
            else cntx++;
            if(i==s.size()-1){
                if(cnt==0){
                    x-=cntx;
                }
                else if (cnt&1){
                    dy.push_back(cnty);
                }else{
                    dx.push_back(cntx);
                }
            }
        }
        if(s[i]=='T'){
            if(cnt==0){
                x -=cntx;
                cntx=0;
            }else if(cnt%2==0){
                dx.push_back(cntx);
                cntx=0;
            }else{
                dy.push_back(cnty);
                cnty=0;
            }
            cnt++;
        }
    }
    // DEBUG{
    //     cout << dx[0] << endl;
    //     cout << dy[0] << endl;
    // }
    sort(dx.begin(),dx.end(),greater<int>()); 
    sort(dy.begin(),dy.end(),greater<int>()); 
    int nowx=x,nowy=y;
    rep(i,dx.size()){
        if(nowx>=0)nowx-=dx[i];
        else nowx+=dx[i];
    }
    rep(i,dy.size()){
        if(nowy>=0)nowy-=dy[i];
        else nowy+=dy[i];
    }
    if(nowx==0&&nowy==0)cout << "Yes" << endl;
    else printf("No\n");
    return 0;
}
