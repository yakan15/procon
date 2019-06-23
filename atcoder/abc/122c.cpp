#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,q;
int main(void) {
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<int,int> > lr;
    rep(i,q){
        int t1,t2;
        cin >> t1 >> t2;
        lr.push_back(make_pair(t1,t2));
    }
    vector<int> cnts;
    int cnt=0;
    cnts.push_back(0);
    rep(i,n){
        if(i==0){cnts.push_back(0);}
        else{
            if(s.substr(i-1,2)=="AC"){
                cnt+=1;
            }
            cnts.push_back(cnt);
        }
    }
    rep(i,q){
        cout << cnts[lr[i].second]-cnts[lr[i].first] << endl;
    }
    return 0;
}
