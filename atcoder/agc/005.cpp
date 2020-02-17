#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
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
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    int mx=0;
    rep(i,n){
        cin>>a[i];
        mp[a[i]]++;
        chmax(mx,a[i]);
    }
    if(n==2){
        cout << (mp[1]==2 ? "Possible" : "Impossible") << endl;
        return 0;
    }
    bool first = true;
    bool second = true,single=false;
    int cnt;
    int prev;
    for(auto x:mp){
        if(first){
            first=false;
            cnt = x.first;
            if(mx%2==0&&x.second==1){
                single=true;

            }
            else if(mx%2==1&&x.second==2){
                cnt--;
            }
            else{
                cout << "Impossible" << endl;
                return 0;
            }
            prev = x.first;
            continue;
        }

        if(x.second<2){
            cout << "Impossible" << endl;
            return 0;
        }
        prev = x.first;
        cnt--;
    }
    cout << (cnt==0 ? "Possible" : "Impossible") << endl;
    return 0;
}
