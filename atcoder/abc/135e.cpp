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
    int k,x,y;
    cin>>k>>x>>y;
    vector<pair<int, int> > res;
    int nx=0,ny=0;
    if((x+y)%2&&k%2==0){
        cout <<-1 << endl;
        return 0;
    }
    while(ny!=y){
        int nxt_dist = min(abs(y-ny), k);
        if(ny<y){
            ny += nxt_dist;
        }else if(ny>y){
            ny-=nxt_dist;
        }
        if(y==ny){
            if(x>0){
                nx += k-nxt_dist;
            }else{
                nx -= k-nxt_dist;
            }
        }
        res.push_back(make_pair(nx,ny));
        DEBUG{cout << nx << " " << ny << endl;}
    }
    int dist=k-abs(nx-x)%k;
    DEBUG{cout << "dist : " <<dist << endl;}
    if (dist%2){
        dist += k;
    }
    rep(i,2){
        if(nx<x){
            nx += k-dist/2;
        }else{
            nx -= k-dist/2;
        }
        res.push_back(make_pair(nx,ny+dist/2*(1-i%2)));
        if(nx==x){break;}
        DEBUG{cout << nx << " " << ny << endl;}
    }
    DEBUG{cout << nx << endl;}
    DEBUG{
        for(auto x:res){
            cout << x.first << " " << x.second << endl;
        }
    }
    int cnt=0;
    while(nx!=x){
        if(nx<x){
            nx += k;
        }else {
            nx -= k;
        }
        res.push_back(make_pair(nx,ny));
        cnt++;
        if(cnt>50000){
            cout << "error" << endl;
            return 0;
        }
    }
    cout << res.size() << endl;
    for(auto r:res){
        cout << r.first << " " << r.second << endl;
    }
    return 0;
}
