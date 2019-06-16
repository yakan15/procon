#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
vector<pair<ll, ll> > py;

string to_num(ll phone){
    string res;
    res = to_string(phone);
    while(res.size()!=12)res = "0"+res;
    return res;
}

int main(void) {
    cin >> n >> m;
    rep(i,m){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        py.push_back(make_pair(tmp1,tmp2));
    } 
    vector<priority_queue<pair<ll, ll> > > vecs(n+1, priority_queue<pair<ll, ll> >());
    rep(i,m){
        vecs[py[i].first].push(make_pair(-1*py[i].second, i));
    }
    vector<pair<ll, ll> > nums;
    ll phone,x;
    rep(i,n+1){
        x = 1;
        while(vecs[i].size()!=0){
            phone = i;
            phone = phone*1000000+x;
            nums.push_back(make_pair(vecs[i].top().second, phone));
            vecs[i].pop();
            x++;
        }
        DEBUG{cout << "nums : " << nums.size() << endl;}
    }
    sort(nums.begin(), nums.end());
    rep(i,m){
        cout << to_num(nums[i].second) << endl;
    }
    return 0;

}
