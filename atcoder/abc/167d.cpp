#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define all(x) begin((x)), end((x))
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<ll> place;
    rep(i,n) {
        cin>>a[i];
        a[i]--;
    }
    place.push_back(0);
    ll now = 0;
    vector<bool> checked(n,false);
    checked[0] = true;
    ll loop;
    while(true) {
        ll next = a[now];
        if (checked[next]) {
            loop = next;
            break;
        }
        place.push_back(next);
        checked[next] = true;
        now = next;
    }
    ll loop_cur = 0;
    while(place[loop_cur]!=loop) {
        loop_cur++;
    }
    // cout << "place: ";
    // for(auto x:place) {
    //     cout << x << " ";
    // }
    if (k<place.size()) {
        cout << place[k]+1 << endl;
    }
    else {
        // cout << "cursor " << (k-loop_cur) % (place.size()-loop_cur) + loop_cur << endl;
        cout <<  place[(k-loop_cur) % (place.size()-loop_cur) + loop_cur]+1 << endl;
    }
    return 0;
}
