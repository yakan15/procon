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
    ll n,m;
    cin >> n >> m;
    vector<pair<int, int> > lst;
    rep(i,m){
        ll ta,tb;
        cin >> ta >> tb;
        lst.push_back(make_pair(tb,ta));
    }
    sort(lst.begin(),lst.end());
    int cnt=0;
    int last=0;
    rep(i,m){
        if(lst[i].second>last){
            last=lst[i].first-1;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

