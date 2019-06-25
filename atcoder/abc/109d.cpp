#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
int h,w;
int main(void) {
    cin >> h>>w;
    bool a[h][w];
    ll cnt=0;
    rep(i,h)rep(j,w){
        ll tmp;
        cin >> tmp;
        a[i][j]=tmp%2==1;
        if(a[i][j])cnt++;
    }
    ll done=0;
    bool state=false;
    vector<string> out;
    rep(i,w){
        if(i%2==0){
            rep(j,h){
                if(done>=cnt/2*2)break;
                if(!state&&a[j][i]){ 
                    state=true;
                    done++;
                    continue;
                }
                if(i==0&&j==0)continue;
                if(state){
                    if(j==0)out.push_back(to_string(j+1)+" "+to_string(i)+" "+to_string(j+1)+" "+to_string(i+1));
                    else out.push_back(to_string(j)+" "+to_string(i+1)+" "+to_string(j+1)+" "+to_string(i+1));
                }
                if(state&&a[j][i]){
                    state=false;
                    done++;
                }
            }
        }else{
            for(int j=h-1;j>=0;j--){
                if(done>=cnt/2*2)break;
                if(!state&&a[j][i]){ 
                    state=true;
                    done++;
                }
                if(i==0&&j==0)continue;
                if(state){
                    if(j==h-1)out.push_back(to_string(j+1)+" "+to_string(i)+" "+to_string(j+1)+" "+to_string(i+1));
                    else out.push_back(to_string(j+2)+" "+to_string(i+1)+" "+to_string(j+1)+" "+to_string(i+1));
                }
                if(state&&a[j][i]){
                    state=false;
                    done++;
                }
            }
        }
    }
    cout << out.size() << endl;
    for(auto x:out){
        cout << x << endl;
    }
    return 0;
}
