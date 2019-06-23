#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,k;
int main(void) {
    cin >> n>>k; 
    vector<pair<ll,ll> > edges;
    ll cnt=0,length=1,cur=2;
    edges.push_back(make_pair(1,2));
    while(cnt<k){
        if(cur+length>=n){
            if(length==1&&cur+length==n){
                cnt++;
                edges.push_back(make_pair(cur,cur+length));
            }
            cur=1;
            length+=2;
            if(cur+length>=n){
                cout << -1 << endl;
                return 0;
            }
        }else{
            edges.push_back(make_pair(cur,cur+length));
            cnt++;
            cur++;
        }
    }
    cout << edges.size() << endl;
    rep(i,edges.size()){
        cout << edges[i].first << " " << edges[i].second << endl;
    }
    return 0;
}
