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
    ll n;
    cin>>n;
    ll a[n];
    rep(i,n){cin>>a[i];}
    sort(a,a+n);
    deque<ll> que;
    ll cur1=0,cur2=n-1;
    que.push_back(a[cur1]);
    cur1++;
    bool nxt=true;
    while(cur2>=cur1){
        if(cur2 == cur1){
            if(abs(que.front()-a[cur2])>abs(que.back()-a[cur2])){
                que.push_front(a[cur2]);
            }
            else{
                que.push_back(a[cur2]);
            }
            cur2--;
        }
        else if(nxt){
            if(que.front()>que.back()){
                que.push_back(a[cur2]);
            }else{
                que.push_front(a[cur2]);
            }
            nxt=false;
            cur2--;
        }else{
            if(que.front()>que.back()){
                que.push_front(a[cur1]);
            }else{
                que.push_back(a[cur1]);
            }
            nxt=true;
            cur1++;
        }
    }
    ll res=0;
    ll prev = que.front();
    while(!que.empty()){
        res += abs(que.front()-prev);
        prev = que.front();
        que.pop_front();
    }
    cout << res << endl;
    return 0;
}
